// src/services/leetcodeService.ts
import axios from 'axios';
import { AuthService } from './authService';

export class LeetCodeService {
    private authService: AuthService;

    constructor() {
        this.authService = new AuthService();
    }

    async getProblemList(): Promise<any[]> {
        const token = await this.authService.getToken();
        if (!token) throw new Error('Not authenticated');

        const response = await axios.get('https://leetcode.com/api/problems/all/', {
            headers: { Authorization: `Bearer ${token}` },
        });

        return response.data.stat.status;
    }

    async submitAnswer(problemId: string, code: string, language: string): Promise<any> {
        const token = await this.authService.getToken();
        if (!token) throw new Error('Not authenticated');

        const response = await axios.post(`https://leetcode.com/problems/${problemId}/submit/`, {
            // Payload structure based on LeetCode's submission API
            data: {
                lang: language,
                question_id: problemId,
                typed_code: code,
            },
            headers: { Authorization: `Bearer ${token}` },
        });

        return response.data;
    }
}