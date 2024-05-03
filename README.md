# Design Pattern - Iterator pattern

## Description

![iterator](https://github.com/jiji-thecat/dp-iterator/assets/104809324/629b8b16-5dd7-4cf6-bbf9-74a062905933)

The Iterator pattern is a design pattern used to easily iterate or provide access to a set of data. For example, suppose you have the following datasets:

- 3 items of Animal type stored in a std::vector.
- 3 items of Animal type stored in a std::list.
- 3 items of Animal type stored in a double array.

Traditionally, accessing data from these datasets requires writing three different methods. For a std::vector, you would access it via `vector[index]`, but std::list does not support this, so you would need to use a pointer. However, by following the Iterator pattern, implementing a simple iterator will allow for easy access.

### Class diagram

![class diagram](https://github.com/jiji-thecat/dp-iterator/assets/104809324/540224f3-09fd-4851-8985-6a042a056fb7)

The datasets will utilize the Aggregate class, while the accessor will employ the Iterator class as an interface.

## How to Install and Run

Import this project as a QT project.

## How to Use This App

![iterator](https://github.com/jiji-thecat/dp-iterator/assets/104809324/629b8b16-5dd7-4cf6-bbf9-74a062905933)

Each image represents different data types (std::vector, std::list, Double array), and it accesses and displays data using the Iterator pattern.

## License

**MIT License**

Copyright © 2024 jiji

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation, the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

\*\*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
