
# The Basics of React

Each react component is a javascript function that returns the html code to show the component. More precisely, it uses an extension of javascript called JSX that allows stuff such as: 

```
const name = 'Josh Perez';
// node that element is not a string and other variables can be used in its definition.
const element = <h1>Hello, {name}</h1>;
```

Complex component can be built from simpler components. Components can have state variables. If some information is important for multiple components, the documentation recommends that it should be centrally stored in a higher level component and passed as argument to the others.

Components tipically communicate with webservice-based APIs with the ```useEffect``` Hook. See the following example extracted from [here](https://www.freecodecamp.org/news/how-to-consume-rest-apis-in-react/).

```
import React, { useState, useEffect } from 'react';

const App = () => {
   const [posts, setPosts] = useState([]);
   useEffect(() => {
      fetch('https://jsonplaceholder.typicode.com/posts?_limit=10')
         .then((response) => response.json())
         .then((data) => {
            console.log(data);
            setPosts(data);
         })
         .catch((err) => {
            console.log(err.message);
         });
   }, []);

    return (
    // ... consume here
    );
};
```

Although the example uses the fetch function that is built-in in newer browsers, a better alternative seems to be the Axios library because it is compatible with older browsers and it is less verbose. The cost of using Axios is a new dependecy in the project.
