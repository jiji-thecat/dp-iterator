# Design Pattern - Iterator pattern

## Description

![sample](https://private-user-images.githubusercontent.com/104809324/326429339-629b8b16-5dd7-4cf6-bbf9-74a062905933.gif?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTQ0NDg4NDYsIm5iZiI6MTcxNDQ0ODU0NiwicGF0aCI6Ii8xMDQ4MDkzMjQvMzI2NDI5MzM5LTYyOWI4YjE2LTVkZDctNGNmNi1iYmY5LTc0YTA2MjkwNTkzMy5naWY_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDMwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQzMFQwMzQyMjZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mNDA5Y2QwODNkN2E0M2EyNDAzNzI3ZWU3ZmVkMGE5ZjAyM2RmMzVhMjY5MmJkNTkyZWViMjFmYTcyNGEwODA0JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.mDxVvaLC3Jx5Ee_Ulef1xBo8UIiTd9x7k26rDkuHZXA)

The Iterator pattern is a design pattern used to easily iterate or provide access to a set of data. For example, suppose you have the following datasets:

- 3 items of Animal type stored in a std::vector.
- 3 items of Animal type stored in a std::list.
- 3 items of Animal type stored in a double array.

Traditionally, accessing data from these datasets requires writing three different methods. For a std::vector, you would access it via `vector[index]`, but std::list does not support this, so you would need to use a pointer. However, by following the Iterator pattern, implementing a simple iterator will allow for easy access.

### Class diagram

![class diagram](https://private-user-images.githubusercontent.com/104809324/326658229-540224f3-09fd-4851-8985-6a042a056fb7.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTQ0NDgzNDAsIm5iZiI6MTcxNDQ0ODA0MCwicGF0aCI6Ii8xMDQ4MDkzMjQvMzI2NjU4MjI5LTU0MDIyNGYzLTA5ZmQtNDg1MS04OTg1LTZhMDQyYTA1NmZiNy5wbmc_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDMwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQzMFQwMzM0MDBaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT05YmRlNGZiNzM5NTAzNGYyNTE4YTQzMGNmMDQyMzIwZGJhZjU2NGEwZWY2NzNhOGExMmQ5MTM3ZjJkOTZhMzc1JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.kBUOx7B6XuKV6bBeuwajPtL_gqE3WOiKyTCeOQaHS3U)

The datasets will utilize the Aggregate class, while the accessor will employ the Iterator class as an interface.

## How to Install and Run

Import this project as a QT project.

## How to Use This App

![sample](https://private-user-images.githubusercontent.com/104809324/326429339-629b8b16-5dd7-4cf6-bbf9-74a062905933.gif?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTUiLCJleHAiOjE3MTQ0NDg4NDYsIm5iZiI6MTcxNDQ0ODU0NiwicGF0aCI6Ii8xMDQ4MDkzMjQvMzI2NDI5MzM5LTYyOWI4YjE2LTVkZDctNGNmNi1iYmY5LTc0YTA2MjkwNTkzMy5naWY_WC1BbXotQWxnb3JpdGhtPUFXUzQtSE1BQy1TSEEyNTYmWC1BbXotQ3JlZGVudGlhbD1BS0lBVkNPRFlMU0E1M1BRSzRaQSUyRjIwMjQwNDMwJTJGdXMtZWFzdC0xJTJGczMlMkZhd3M0X3JlcXVlc3QmWC1BbXotRGF0ZT0yMDI0MDQzMFQwMzQyMjZaJlgtQW16LUV4cGlyZXM9MzAwJlgtQW16LVNpZ25hdHVyZT1mNDA5Y2QwODNkN2E0M2EyNDAzNzI3ZWU3ZmVkMGE5ZjAyM2RmMzVhMjY5MmJkNTkyZWViMjFmYTcyNGEwODA0JlgtQW16LVNpZ25lZEhlYWRlcnM9aG9zdCZhY3Rvcl9pZD0wJmtleV9pZD0wJnJlcG9faWQ9MCJ9.mDxVvaLC3Jx5Ee_Ulef1xBo8UIiTd9x7k26rDkuHZXA)

Each image represents different data types (std::vector, std::list, Double array), and it accesses and displays data using the Iterator pattern.

## License

**MIT License**

Copyright © 2024 jiji

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation, the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

\*\*THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
