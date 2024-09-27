"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
// The module 'vscode' contains the VS Code extensibility API
// Import the module and reference it with the alias vscode in your code below
const vscode = __importStar(require("vscode"));
const authService_1 = require("./services/authService");
const leetcodeService_1 = require("./services/leetcodeService");
const languageMapper_1 = require("./utils/languageMapper");
// This method is called when your extension is activated
// Your extension is activated the very first time the command is executed
function activate(context) {
    const authService = new authService_1.AuthService();
    const leetCodeService = new leetcodeService_1.LeetCodeService();
    let loginCommand = vscode.commands.registerCommand('vscode-leetcode.login', () => __awaiter(this, void 0, void 0, function* () {
        const username = yield vscode.window.showInputBox({ prompt: 'LeetCode Username' });
        const password = yield vscode.window.showInputBox({ prompt: 'LeetCode Password', password: true });
        if (username && password) {
            try {
                yield authService.login(username, password);
                vscode.window.showInformationMessage('Login successful!');
            }
            catch (error) {
                vscode.window.showErrorMessage('Login failed. Please check your credentials.');
            }
        }
    }));
    let submitCommand = vscode.commands.registerCommand('vscode-leetcode.submit', () => __awaiter(this, void 0, void 0, function* () {
        const editor = vscode.window.activeTextEditor;
        if (!editor) {
            vscode.window.showErrorMessage('No active editor');
            return;
        }
        const code = editor.document.getText();
        const language = (0, languageMapper_1.getLanguage)(editor.document.languageId);
        const problemId = yield vscode.window.showInputBox({ prompt: 'Enter LeetCode Problem ID' });
        if (problemId) {
            try {
                const result = yield leetCodeService.submitAnswer(problemId, code, language);
                vscode.window.showInformationMessage(`Submission Status: ${result.status_msg}`);
            }
            catch (error) {
                vscode.window.showErrorMessage('Submission failed.');
            }
        }
    }));
    context.subscriptions.push(loginCommand);
    context.subscriptions.push(submitCommand);
}
// This method is called when your extension is deactivated
function deactivate() { }
