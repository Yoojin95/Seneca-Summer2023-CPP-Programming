/* 
    1) 'Pass by Value' vs 'Pass by Reference'
    
        * Pass by Value
         -> when an object is passed by value, a copy of the object is made, which can be time-consuming and memory-intensive for large object.
         -> any modifications made to the copy within the function do not affect the original object outside the function (local)
     
        * Pass by Reference
        -> allows to access and manipulate the original object without creating a copy
        -> any modifications made to reference will affect the original object
        -> can use a null reference or a reference to an exsiting object providing optionality of haveing no object to process
        -> polymorphism and inheritance in C++   

*/