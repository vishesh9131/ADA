// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
import * as vscode from 'vscode';
import { AuthService } from './services/authService';
import { LeetCodeService } from './services/leetcodeService';
import { getLanguage } from './utils/languageMapper';

// This method is called when your extension is activated
// Your extension is activated the very first time the command is executed
export function activate(context: vscode.ExtensionContext) {
    const authService = new AuthService();
    const leetCodeService = new LeetCodeService();

    let loginCommand = vscode.commands.registerCommand('vscode-leetcode.login', async () => {
        const username = await vscode.window.showInputBox({ prompt: 'LeetCode Username' });
        const password = await vscode.window.showInputBox({ prompt: 'LeetCode Password', password: true });

        if (username && password) {
            try {
                await authService.login(username, password);
                vscode.window.showInformationMessage('Login successful!');
            } catch (error) {
                vscode.window.showErrorMessage('Login failed. Please check your credentials.');
            }
        }
    });

    let submitCommand = vscode.commands.registerCommand('vscode-leetcode.submit', async () => {
        const editor = vscode.window.activeTextEditor;
        if (!editor) {
            vscode.window.showErrorMessage('No active editor');
            return;
        }

        const code = editor.document.getText();
        const language = getLanguage(editor.document.languageId);
        const problemId = await vscode.window.showInputBox({ prompt: 'Enter LeetCode Problem ID' });

        if (problemId) {
            try {
                const result = await leetCodeService.submitAnswer(problemId, code, language);
                vscode.window.showInformationMessage(`Submission Status: ${result.status_msg}`);
            } catch (error) {
                vscode.window.showErrorMessage('Submission failed.');
            }
        }
    });

    context.subscriptions.push(loginCommand);
    context.subscriptions.push(submitCommand);
}

// This method is called when your extension is deactivated
export function deactivate() {}
