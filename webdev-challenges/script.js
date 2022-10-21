// Using the index.html and style.css files in this folder, do the following:
// DONE - If you click on the list item, it toggles the .done class on and off.
// Add buttons next to each list item to delete the item when clicked on its corresponding delete button.
// BONUS: When adding a new list item, it automatically adds the delete button next to it (hint: be sure to check if new items are clickable too!)

var button = document.getElementById("enter");
var input = document.getElementById("userinput");
var ul = document.querySelector("ul");

function createListElement() {
	var li = document.createElement("li");
	var delButton = document.createElement("button");
	li.appendChild(document.createTextNode(input.value + "             "));
	ul.appendChild(li);
	input.value = "";
	delButton.className = "delButton";
	delButton.innerHTML = "Delete";	
	li.appendChild(delButton);	
}

function inputLength() {
	return input.value.length;
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

function toggleDone(item) {
	if (item.target.tagName === "LI") {
		item.target.classList.toggle("done");
	}		
}

function deleteListItem(item) {
	if (item.target.className === "delButton") {
		item.target.parentElement.remove();
		console.log("did it work?");
	}
}

button.addEventListener("click", addListAfterClick);
input.addEventListener("keypress", addListAfterKeypress);
ul.addEventListener("click", toggleDone)
ul.addEventListener("click",deleteListItem)