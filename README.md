# PHP Rootkit
PHP module based rootkit to intercept standard-library & module function calls.


## Compilation
To prevent malicious script kiddies from getting their hands on a weaponized PHP module, I've removed the compilation instructions alongside the implementation of the method hooks. 

Furthermore, I will not be releasing pre-compiled binaries. Any semi-experienced C developer should be able to find out how to compile PHP modules and implement the the `rootkit_hook_function` 
method.

Issues created regarding this will not be addressed and closed.


## Disclaimer
Using this module might cause severe damage to your system, it was created as a proof of concept and should
never be used on a production system!

By using this software the person in question agrees that they will use any of software in question in an ethical (non-malicious) way and agrees that the developer(s) are NOT held responsible for any damage caused by the use and or abuse of this software.

Misuse of any software from this website may result in criminal charges brought against the person in question depending on the country or state of residence which can result in probation, fines up or prison sentences up to 20 years in federal prison. 


## License
Copyright 2017 - Luke Paris (Paradoixs)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
