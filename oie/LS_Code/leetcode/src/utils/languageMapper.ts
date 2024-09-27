export function getLanguage(vscodeLanguageId: string): string {
    const mapping: { [key: string]: string } = {
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