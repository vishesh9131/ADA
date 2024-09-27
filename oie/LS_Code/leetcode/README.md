# VSCode LeetCode Extension

![VSCode Marketplace](https://img.shields.io/vscode-marketplace/v/your-publisher/vscode-leetcode)
![Installs](https://img.shields.io/vscode-marketplace/d/your-publisher/vscode-leetcode)
![License](https://img.shields.io/github/license/your-username/vscode-leetcode)

## Overview

**VSCode LeetCode** is a powerful Visual Studio Code extension that seamlessly integrates [LeetCode](https://leetcode.com/) into your coding environment. With this extension, you can effortlessly log in to LeetCode, browse problems, write solutions, and submit your answers—all without leaving VS Code.

## Features

- **Direct Login to LeetCode:** Authenticate your LeetCode account within VS Code.
- **Browse LeetCode Problems:** Access the full list of LeetCode problems and view problem details.
- **Write and Edit Solutions:** Utilize VS Code's robust editing features to write your code.
- **Submit Solutions:** Submit your answers to LeetCode directly from the editor and view submission results.
- **Problem Navigation:** Easily navigate between problems and your solution files.
- **Supported Languages:** Multiple programming languages supported for solutions (e.g., Python, JavaScript, Java, C++, etc.).

## Installation

### Prerequisites

- **Visual Studio Code:** Ensure you have the latest version installed. [Download VS Code](https://code.visualstudio.com/)
- **Node.js:** Install Node.js from the [official website](https://nodejs.org/).
- **Yeoman and VS Code Extension Generator:**

  ```bash
  npm install -g yo generator-code
  ```

### Installing the Extension

#### From the VS Code Marketplace

1. Open VS Code.
2. Go to the Extensions view by clicking on the Extensions icon in the Activity Bar or pressing `Ctrl+Shift+X` (`Cmd+Shift+X` on macOS).
3. Search for "**VSCode LeetCode**".
4. Click **Install**.

#### From Source

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/your-username/vscode-leetcode.git
   cd vscode-leetcode
   ```

2. **Install Dependencies:**

   ```bash
   npm install
   ```

3. **Compile the Extension:**

   ```bash
   npm run compile
   ```

4. **Package the Extension:**

   Ensure you have `vsce` installed:

   ```bash
   npm install -g vsce
   vsce package
   ```

5. **Install the Extension:**

   ```bash
   code --install-extension vscode-leetcode-0.0.1.vsix
   ```

## Usage

### 1. **Login to LeetCode**

- **Command Palette:**
  - Press `Ctrl+Shift+P` (`Cmd+Shift+P` on macOS) to open the Command Palette.
  - Type `LeetCode: Login` and select it.
  
- **Input Credentials:**
  - Enter your LeetCode **Username**.
  - Enter your LeetCode **Password**.

- **Confirmation:**
  - A success message will appear upon successful login.

### 2. **Browse and Select Problems**

- **Command Palette:**
  - Open the Command Palette.
  - Type `LeetCode: Show Problems` and select it.

- **Problem List:**
  - A sidebar will display a list of available LeetCode problems.
  - Click on any problem to open its details.

### 3. **Write and Edit Solutions**

- **Open Editor:**
  - Click on a problem to open a new editor window with the problem details.
  
- **Write Code:**
  - Utilize VS Code's powerful editing features to write your solution in your preferred programming language.

### 4. **Submit Solutions**

- **Command Palette:**
  - With your solution open, press `Ctrl+Shift+P` (`Cmd+Shift+P` on macOS) to open the Command Palette.
  - Type `LeetCode: Submit Solution` and select it.

- **Submission:**
  - The extension will submit your code to LeetCode.
  - View the submission status and results directly within VS Code.

## Commands

| Command                     | Description                              |
| --------------------------- | ---------------------------------------- |
| `LeetCode: Login`           | Authenticate your LeetCode account        |
| `LeetCode: Logout`          | Sign out of your LeetCode account         |
| `LeetCode: Show Problems`   | Display a list of available LeetCode problems |
| `LeetCode: Submit Solution` | Submit your current solution to LeetCode   |
| `LeetCode: Show Submissions`| View your submission history               |

> **Tip:** You can view all available commands by opening the Command Palette (`Ctrl+Shift+P` or `Cmd+Shift+P` on macOS) and typing `LeetCode`.

## Configuration

You can customize the extension settings to fit your workflow.

### Settings

- **LeetCode API Endpoint:**
  - If LeetCode updates their API or if you need to use a custom endpoint, you can configure it in the settings.

- **Default Programming Language:**
  - Set your preferred programming language for new problems.

### Accessing Settings

1. Open VS Code settings:
   - Go to `File` > `Preferences` > `Settings` (`Code` > `Preferences` > `Settings` on macOS).
2. Search for `LeetCode` to view and modify available settings.

## Contributing

Contributions are welcome! If you'd like to contribute to the development of the VSCode LeetCode extension, please follow these guidelines:

### Steps to Contribute

1. **Fork the Repository:**

   Click the **Fork** button on the [GitHub repository](https://github.com/your-username/vscode-leetcode) to create a personal copy.

2. **Clone Your Fork:**

   ```bash
   git clone https://github.com/your-username/vscode-leetcode.git
   cd vscode-leetcode
   ```

3. **Install Dependencies:**

   ```bash
   npm install
   ```

4. **Create a New Branch:**

   ```bash
   git checkout -b feature/YourFeatureName
   ```

5. **Make Your Changes:**

   Implement your enhancements or bug fixes.

6. **Commit Your Changes:**

   ```bash
   git commit -m "Add feature: YourFeatureName"
   ```

7. **Push to Your Fork:**

   ```bash
   git push origin feature/YourFeatureName
   ```

8. **Create a Pull Request:**

   Navigate to the original repository and create a pull request detailing your changes.

### Code of Conduct

Please adhere to the [Contributor Covenant Code of Conduct](https://www.contributor-covenant.org/) to ensure a welcoming environment for all contributors.

## License

This project is licensed under the [MIT License](LICENSE).

## Feedback and Support

If you encounter any issues or have suggestions for improvements, feel free to [open an issue](https://github.com/your-username/vscode-leetcode/issues) on GitHub.

Connect with other users and stay updated with the latest releases:

- **GitHub Repository:** [https://github.com/your-username/vscode-leetcode](https://github.com/your-username/vscode-leetcode)
- **VSCode Marketplace:** [VSCode LeetCode Extension](https://marketplace.visualstudio.com/items?itemName=your-publisher.vscode-leetcode)

---

> **Happy Coding!** 🚀
