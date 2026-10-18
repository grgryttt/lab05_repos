#pragma once

// Номер людини, що залишилась у колі з n людей.
// level - поточний рівень рекурсії, depth - глибина (максимальний досягнутий рівень)
int f(const int n, const int level, int& depth);