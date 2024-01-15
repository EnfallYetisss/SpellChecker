# Spell Checker

A simple spell checker program implemented in C++.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Acknowledgments](#acknowledgments)

## Introduction

This spell checker program checks the spelling of a given word against a dictionary and suggests alternatives if the word is not found.

## Features

- Spell checking based on a dictionary.
- Suggestions for misspelled words.

## Getting Started

### Prerequisites

- C++ compiler
- Words file (e.g., `words.txt`)

### Installation

1. Clone the repository:

    ```bash
    git clone https://github.com/EnfallYetisss/SpellChecker.git
    cd SpellChecker
    ```

2. Download the `words.txt` file from [MIT Word List](https://www.mit.edu/~ecprice/wordlist.10000) and place it in the project directory.

3. Compile the program:

    ```bash
    g++ spell_checker.cpp -o spell_checker
    ```

## Usage

1. Add words to the dictionary by editing the `words.txt` file.
2. Run the spell checker:

    ```bash
    ./spell_checker
    ```

3. Enter a word to check its spelling.

## Acknowledgments

- Thanks to the [C++ Standard Library](https://en.cppreference.com/w/cpp/header) for providing useful features.
- The `words.txt` file is sourced from the [MIT Word List](https://www.mit.edu/~ecprice/wordlist.10000).
