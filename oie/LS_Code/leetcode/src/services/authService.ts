// src/services/authService.ts
import axios from 'axios';
import * as keytar from 'keytar';

const SERVICE_NAME = 'vscode-leetcode';
const ACCOUNT_NAME = 'leetcode';

export class AuthService {
    async login(username: string, password: string): Promise<void> {
        // LeetCode authentication API endpoint
        const response = await axios.post('https://leetcode.com/accounts/login/', {
            username,
            password,
        });

        if (response.status === 200) {
            const token = response.data.auth_token;
            await keytar.setPassword(SERVICE_NAME, ACCOUNT_NAME, token);
        } else {
            throw new Error('Login failed');
        }
    }

    async getToken(): Promise<string | null> {
        return await keytar.getPassword(SERVICE_NAME, ACCOUNT_NAME);
    }

    async logout(): Promise<void> {
        await keytar.deletePassword(SERVICE_NAME, ACCOUNT_NAME);
    }
}