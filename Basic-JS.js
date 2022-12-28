// using this array,
// var array = ["Banana", "Apples", "Oranges", "Blueberries"];
// 1. Remove the Banana from the array.
// 2. Sort the array in order.
// 3. Put "Kiwi" at the end of the array.
// 4. Remove "Apples" from the array.
// 5. Sort the array in reverse order. (Not alphabetical, but reverse
// the current Array i.e. ['a', 'c', 'b'] becomes ['b', 'c', 'a'])
// you should have at the end:
// ["Kiwi", "Oranges", "Blueberries"]
// using this array,
// var array2 = ["Banana", ["Apples", ["Oranges"], "Blueberries"]];
// access "Oranges".

var array = ["Banana", "Apples", "Oranges", "Blueberries"];
array.shift();
array.sort();
array.push("Kiwi");
array.shift();
array.reverse();
console.log(array);
var array2 = ["Banana", ["Apples", ["Oranges"], "Blueberries"]];
console.log(array2[1][1][0]);


// Create an object and an array which we will use in our facebook exercise. 
// 1. Create an object that has properties "username" and "password". Fill those values in with strings.
// 2. Create an array which contains the object you have made above and name the array "database".
// 3. Create an array called "newsfeed" which contains 3 objects with properties "username" and "timeline".

var person = {
  username: "Alex",
  password: "password",
};

var database = [person];

var newsfeed = [
  {
    username: "Terry",
    timeline: "Terry loooooooooooves yogurt!"
  },
  {
    username: "Boyle",
    timeline: "I wrote about the best yogurt shop last Tuesday..."
  },
  {
    username: "Holt",
    timeline: "I am writing a post today about how I am feeling."
  }
];


//Evaluate these:
//#1
[2] === [2] // false
{} === {} // false

//#2 what is the value of property a for each object.
const object1 = { a: 5 }; 
const object2 = object1;  
const object3 = object2;  
const object4 = { a: 5};  
object1.a = 4;
// o1 - o3 a === 4 and o4 a === 5

//#3 create two classes: an Animal class and a Mamal class. 
// create a cow that accepts a name, type and color and has a sound method that moo's her name, type and color. 

class Animal {
  constructor(name, type, color) {
    this.name = name;
    this.type = type;
    this.color = color;
  }
}

class Mamal extends Animal {
  constructor(name, type, color) {
    super(name, type, color);
  }
  moo() {
    console.log(`MOOOOOOOOoooooOOO I'm ${this.name}. I am a ${this.type} that looks ${this.color}`);
  }
}

const cow1 = new Mamal ('Betsy', 'Cow', 'Purple')


// #1) Check if this array includes the name "John".
const dragons = ['Tim', 'Johnathan', 'Sandy', 'Sarah'];
dragons.includes('John')

// #2) Check if this array includes any name that has "John" inside of it. If it does, return that
// name or names in an array.
const dragons = ['Tim', 'Johnathan', 'Sandy', 'Sarah'];
dragons.filter(name => name.includes('John'));

// #3) Create a function that calulates the power of 100 of a number entered as a parameter
function hundredPower(num) {
  a = num**100;
  console.log(a);
}

// #4) Useing your function from #3, put in the paramter 10000. What is the result?
// Research for yourself why you get this result
hundredPower(10000) === Infinity //useful to set limits if calculating something where the values become too large