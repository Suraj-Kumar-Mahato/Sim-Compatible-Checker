from flask import Flask, request, jsonify, send_from_directory
import subprocess
import sqlite3
import os

app = Flask(__name__)

# Path to project directory
PROJECT_DIR = os.path.dirname(os.path.abspath(__file__))

# Basic API key (for simple security)
API_KEY = "your-secret-api-key"

# Serve HTML
@app.route('/')
def serve_index():
    return send_from_directory(PROJECT_DIR, 'index.html')

# Serve CSS
@app.route('/style.css')
def serve_css():
    return send_from_directory(PROJECT_DIR, 'style.css')

# Serve JavaScript
@app.route('/script.js')
def serve_js():
    return send_from_directory(PROJECT_DIR, 'script.js')

# Get SIM suggestions from SQLite (optional, if you're using sim_data.db)
def get_sim_suggestions(region):
    conn = sqlite3.connect('sim_data.db')
    cursor = conn.cursor()
    cursor.execute("SELECT sim_name FROM sims WHERE region=?", (region,))
    sims = cursor.fetchall()
    conn.close()
    return [sim[0] for sim in sims]

# Route to fetch SIM list (if needed)
@app.route('/get_sim', methods=['POST'])
def get_sim():
    region = request.form.get('region')
    sims = get_sim_suggestions(region)
    return jsonify(sims)

# Call C++ executable to get SIM compatibility
@app.route('/process_location', methods=['POST'])
def process_location():
    # API Key check
    client_api_key = request.headers.get("X-API-Key")
    if client_api_key != API_KEY:
        return jsonify({'error': 'Unauthorized request'}), 401

    location = request.form.get('location')
    if not location:
        return jsonify({'error': 'Location is required'}), 400

    try:
        # Call C++ program (make sure it's compiled and available in the same dir)
        result = subprocess.run(['./process_location.exe', location], capture_output=True, text=True)
        return jsonify({'message': result.stdout.strip()})
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(debug=True)
