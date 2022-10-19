// Using the index.html and style.css files in this folder, do the following:
// DONE - If you click on the list item, it toggles the .done class on and off.
// Add buttons next to each list item to delete the item when clicked on its corresponding delete button.
	// get the button added when li created
	// add functionality to button to actually remove corresponding li
		// get button to recognize it's li when clicked
		// figure out removal
// BONUS: When adding a new list item, it automatically adds the delete button next to it (hint: be sure to check if new items are clickable too!)
	// new list items are not clickable because the var li is created once when the page is loaded...
// MY EXTRAS: have the cursor change to a hand when hovering over list items

var button = document.getElementById("enter");
var input = document.getElementById("userinput");
var ul = document.querySelector("ul");
var li = document.querySelectorAll("li"); // li is now an array of all the list items

function inputLength() {
	return input.value.length;
}

function createListElement() {
	var li = document.createElement("li");
	li.appendChild(document.createTextNode(input.value));
	ul.appendChild(li);
	input.value = "";
}

function addListAfterClick() {
	if (inputLength() > 0) {
		createListElement();
	}
}

function addListAfterKeypress(event) {
	if (inputLength() > 0 && event.keyCode === 13) {
		createListElement();
	}
}

button.addEventListener("click", addListAfterClick);

input.addEventListener("keypress", addListAfterKeypress);

for (let x of li) {
	x.addEventListener("click", function() {
		x.classList.toggle("done");
	});
}