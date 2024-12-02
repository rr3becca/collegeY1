function getReady(){
    document.getElementById("message").innerHTML = "YOU ARE NOW READY FOR FACTS!!" //the text changes when the button is pressed
}

function darkMode() {
    var element = document.body;
    var content = document.getElementById("DarkModetext");
    element.className = "dark-mode";
    content.innerText = "Dark Mode is ON";
    let imageMode = document.getElementById("mode");
    imageMode.src = "https://upload.wikimedia.org/wikipedia/commons/e/e1/FullMoon2010.jpg";
    
  }
  function lightMode() {
    var element = document.body;
    var content = document.getElementById("DarkModetext");//changes from light mode to dark mode
    element.className = "light-mode";
    content.innerText = "Dark Mode is OFF";
    let imageMode = document.getElementById("mode");
  }


const myInterval = setInterval(myTimer, 1000);

function myTimer() {
  const date = new Date();
  document.getElementById("demo").textContent = date.toLocaleTimeString(); //stops the timer
}

function myStopFunction() {
  clearInterval(myInterval);
}



//CODE DOES NOT DISPLAY - POSSIBLY ELEMENT BLOCKING IT
const items = ['Barbie', 'Spider-man', 'Avatar', 'Step Brothers', 'Mario', 'Avengers'];

// Function to display Movies on the webpage
function displayMovies() {
  const movieList = document.getElementById('movie-list');

  items.forEach(movie => {
    // Create a new list item element
    const listItem = document.createElement('li');
    
    // Set the text content of the list item
    listItem.textContent = movie;

    // Append the list item to the unordered list
    movieList.appendChild(listItem);
  });
}
displayMovies();

// Example object representing Barbie
const movie = {
  name: 'Barbie',
  made: '2023',
  worth: '1.4B'
};
// Function to display Movie information on the webpage
function displayMovieInfo() {
//Select the div with id movie-info
  const movieInfoContainer = document.getElementById('movie-info');
  // Display the movie object properties on the webpage
  movieInfoContainer.innerHTML = `
    <p>Name: ${movie.name}</p>
    <p>Made: ${movie.made}</p>
    <p>Worth: ${movie.worth}</p>
  `;
}

// Call the function to display county information
displayMovieInfo();



document.getElementById('contactForm').addEventListener('submit', function(event) {
  event.preventDefault(); // Prevents the default form submission
  
  // Get form values
  var name = document.getElementById('name').value;
  var email = document.getElementById('email').value;
  var message = document.getElementById('message').value;

  // Display captured values (for demonstration purposes)
  console.log('Name:', name);
  console.log('Email:', email);
  console.log('Message:', message);

  
  document.getElementById('name').value = '';
  document.getElementById('email').value = '';
  document.getElementById('message').value = '';
});
