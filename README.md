# Facebook Console App

This is a simple console application written in C++ that provides essential Facebook functionalities such as commenting on posts, liking posts, etc. It is heavily based on Object-Oriented Programming (OOP) principles.

## Features

- **Post Creation**: Users can create new posts on their timeline.
- **Post Interaction**: Users can like and comment on posts.
- **View Timeline**: Users can view their timeline to see posts and interactions.
- **Basic User Authentication**: Users can log in to access their timeline and perform actions.

## Object-Oriented Design

This application is designed with Object-Oriented Programming (OOP) principles in mind, with key features including:

- **Encapsulation**: Data and methods relevant to each entity (e.g., User, Post, Facebook) are encapsulated within their respective classes, promoting modularity and abstraction.

- **Inheritance**: Where appropriate, inheritance is utilized to establish relationships between classes. For instance, the User class may inherit from a base class representing a generic social media user.

- **Polymorphism**: Polymorphism allows for flexibility and extensibility in the application. For example, different types of posts (e.g., text post, image post) may share a common interface but exhibit different behaviors.

- **Abstraction**: Complex implementation details are abstracted away, allowing users of the application to interact with high-level, intuitive interfaces.

## Requirements

- C++ compiler (supporting C++11 or later)
- Standard C++ library

## How to Use

1. Clone or download this repository to your local machine.
2. Compile the source files using a C++ compiler.
    ```bash
    g++ -std=c++11 main.cpp Facebook.cpp User.cpp Post.cpp -o facebook_app
    ```
3. Run the compiled executable.
    ```bash
    ./facebook_app
    ```
4. Follow the on-screen instructions to log in, create posts, like posts, comment on posts, and view the timeline.

## File Structure

- `main.cpp`: Entry point of the application.
- `comments.txt`: contains the comments on posts.
- `pages.txt`: the details of facebook pages
- `users.txt`: the list of users and their connections
- `posts.txt`: the details of the posts created

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or bug fixes, feel free to open an issue or submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
