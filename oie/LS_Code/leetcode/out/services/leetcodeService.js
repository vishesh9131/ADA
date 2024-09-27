"use strict";
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
exports.LeetCodeService = void 0;
// src/services/leetcodeService.ts
const axios_1 = __importDefault(require("axios"));
const authService_1 = require("./authService");
class LeetCodeService {
    constructor() {
        this.authService = new authService_1.AuthService();
    }
    getProblemList() {
        return __awaiter(this, void 0, void 0, function* () {
            const token = yield this.authService.getToken();
            if (!token)
                throw new Error('Not authenticated');
            const response = yield axios_1.default.get('https://leetcode.com/api/problems/all/', {
                headers: { Authorization: `Bearer ${token}` },
            });
            return response.data.stat.status;
        });
    }
    submitAnswer(problemId, code, language) {
        return __awaiter(this, void 0, void 0, function* () {
            const token = yield this.authService.getToken();
            if (!token)
                throw new Error('Not authenticated');
            const response = yield axios_1.default.post(`https://leetcode.com/problems/${problemId}/submit/`, {
                // Payload structure based on LeetCode's submission API
                data: {
                    lang: language,
                    question_id: problemId,
                    typed_code: code,
                },
                headers: { Authorization: `Bearer ${token}` },
            });
            return response.data;
        });
    }
}
exports.LeetCodeService = LeetCodeService;
