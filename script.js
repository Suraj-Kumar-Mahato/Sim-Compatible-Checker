document.getElementById('locationForm').addEventListener('submit', function(event) {
    event.preventDefault();

    const location = document.getElementById('location').value;

    fetch('/process_location', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
            'X-API-Key': 'your-secret-api-key'  // Secure this
        },
        body: new URLSearchParams({ location: location })
    })
    .then(response => response.json())
    .then(data => {
        if (data.message) {
            document.getElementById('simSuggestions').innerHTML = `<p>${data.message.replace(/\n/g, '<br>')}</p>`;
        } else {
            alert('Error: ' + data.error);
        }
    })
    .catch(error => alert('Error: ' + error));
});
