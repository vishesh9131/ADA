"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.getLanguage = getLanguage;
function getLanguage(vscodeLanguageId) {
    const mapping = {
        'javascript': 'javascript',
        'typescript': 'typescript',
        'python': 'python3',
        'java': 'java',
        'csharp': 'csharp',
        'cpp': 'cpp',
        'c': 'c',
        'ruby': 'ruby',
        'go': 'golang',
        'swift': 'swift',
        'kotlin': 'kotlin',
        // Add more mappings as needed
    };
    return mapping[vscodeLanguageId] || 'python3'; // Default to 'python3' if language not found
}
