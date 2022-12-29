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


// #1 Turn this array into a new array: [1,2,3,[4],[5]]. Bonus if you can do it on one line
const array = [[1],[2],[3],[[[4]]],[[[5]]]]
array.flat(2)

// #2 Turn this array into a new array: [ 'Hello young grasshopper!', 'you are', 'learning fast!' ]
const greeting = [["Hello", "young", "grasshopper!"], ["you", "are"], ["learning", "fast!"]];
const greeting2 = greeting.flatMap(x => x.join(' '))


//#3 Turn the greeting array above into a string: 'Hello young grasshopper you are learning fast!'
const greeting3 = greeting2.join(' ')


//#4 Turn the trapped 3 number into: [3]
const trapped = [[[[[[[[[[[[[[[[[[[[[[[[[[3]]]]]]]]]]]]]]]]]]]]]]]]]];
trapped.flat(Infinity)



//#5 Clean up this email to have no whitespaces. Make the answer be in a single line (return a new string):
const userEmail3 = '     cannotfillemailformcorrectly@gmail.com   '
const userEmail4 = userEmail3.trimStart().trimEnd()
console.log(userEmail4)


//#6 Turn the below users (value is their ID number) into an array: [ [ 'user1', 18273 ], [ 'user2', 92833 ], [ 'user3', 90315 ] ]
const users = { user1: 18273, user2: 92833, user3: 90315 }
const users2 = Object.entries(users)

//#7 change the output array of the above to have the user's IDs multiplied by 2 -- Should output:[ [ 'user1', 36546 ], [ 'user2', 185666 ], [ 'user3', 180630 ] ]
const users3 = users2.map((users) => [users[0], user[1] * 2])

//#8 change the output array of question #7 back into an object with all the users IDs updated to their new version. Should output: { user1: 36546, user2: 185666, user3: 180630 }
users4 = Object.fromEntries(users3)