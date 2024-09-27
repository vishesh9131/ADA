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
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.AuthService = void 0;
// src/services/authService.ts
const axios_1 = __importDefault(require("axios"));
const keytar = __importStar(require("keytar"));
const SERVICE_NAME = 'vscode-leetcode';
const ACCOUNT_NAME = 'leetcode';
class AuthService {
    login(username, password) {
        return __awaiter(this, void 0, void 0, function* () {
            // LeetCode authentication API endpoint
            const response = yield axios_1.default.post('https://leetcode.com/accounts/login/', {
                username,
                password,
            });
            if (response.status === 200) {
                const token = response.data.auth_token;
                yield keytar.setPassword(SERVICE_NAME, ACCOUNT_NAME, token);
            }
            else {
                throw new Error('Login failed');
            }
        });
    }
    getToken() {
        return __awaiter(this, void 0, void 0, function* () {
            return yield keytar.getPassword(SERVICE_NAME, ACCOUNT_NAME);
        });
    }
    logout() {
        return __awaiter(this, void 0, void 0, function* () {
            yield keytar.deletePassword(SERVICE_NAME, ACCOUNT_NAME);
        });
    }
}
exports.AuthService = AuthService;
