//itzhak173@gmail.com

#include "SquareMat.hpp"
#include <iostream>

using namespace MatOps;

int main() {
    std::cout << "===== Basic 2x2 Matrix Examples =====\n";
    
    // יצירת מטריצות 2x2
    SquareMat m1(2);
    m1[0][0] = 1; m1[0][1] = 2;
    m1[1][0] = 3; m1[1][1] = 4;
    
    SquareMat m2(2, 2.0);
    
    std::cout << "Matrix m1:\n" << m1 << std::endl;
    std::cout << "Matrix m2:\n" << m2 << std::endl;
    
    // חיבור וחיסור
    std::cout << "m1 + m2:\n" << m1 + m2 << std::endl;
    std::cout << "m1 - m2:\n" << m1 - m2 << std::endl;
    
    // כפל מטריצות וכפל סקלרי
    std::cout << "m1 * m2:\n" << m1 * m2 << std::endl;
    std::cout << "m1 * 2.5:\n" << m1 * 2.5 << std::endl;
    std::cout << "2.5 * m1:\n" << 2.5 * m1 << std::endl;
    
    // אופרטורים אונאריים
    std::cout << "Transpose of m1:\n" << ~m1 << std::endl;
    std::cout << "Negative of m1:\n" << -m1 << std::endl;
    std::cout << "Determinant of m1: " << !m1 << std::endl;
    
    // פעולות איבר-איבר
    std::cout << "Element-wise multiplication (m1 % m2):\n" << m1 % m2 << std::endl;
    
    // מודולו עם סקלר
    std::cout << "m1 % 3 (modulo):\n" << m1 % 3 << std::endl;
    
    // חילוק בסקלר
    std::cout << "m1 / 2.0:\n" << m1 / 2.0 << std::endl;
    
    // אופרטורי הגדלה והקטנה
    SquareMat m3 = m1;
    std::cout << "Original m3:\n" << m3 << std::endl;
    std::cout << "++m3:\n" << ++m3 << std::endl;
    std::cout << "m3++:\n" << m3++ << std::endl;
    std::cout << "After post-increment:\n" << m3 << std::endl;
    
    // אופרטורי השוואה
    std::cout << "m1 == m2? " << (m1 == m2) << std::endl;
    std::cout << "m1 != m2? " << (m1 != m2) << std::endl;
    std::cout << "m1 < m2? " << (m1 < m2) << std::endl;
    
    // אופרטורי השמה משולבים
    m1 += m2;
    std::cout << "After m1 += m2:\n" << m1 << std::endl;
    
    std::cout << "\n===== Larger 3x3 Matrix Examples =====\n";
    
    // יצירת מטריצות 3x3
    SquareMat large1(3);
    large1[0][0] = 1; large1[0][1] = 2; large1[0][2] = 3;
    large1[1][0] = 4; large1[1][1] = 5; large1[1][2] = 6;
    large1[2][0] = 7; large1[2][1] = 8; large1[2][2] = 9;
    
    SquareMat large2(3);
    large2[0][0] = 9; large2[0][1] = 8; large2[0][2] = 7;
    large2[1][0] = 6; large2[1][1] = 5; large2[1][2] = 4;
    large2[2][0] = 3; large2[2][1] = 2; large2[2][2] = 1;
    
    std::cout << "3x3 Matrix large1:\n" << large1 << std::endl;
    std::cout << "3x3 Matrix large2:\n" << large2 << std::endl;
    
    // חיבור מטריצות 3x3
    std::cout << "large1 + large2:\n" << large1 + large2 << std::endl;
    
    // כפל מטריצות 3x3
    std::cout << "large1 * large2:\n" << large1 * large2 << std::endl;
    
    // חזקה של מטריצה
    std::cout << "large1^2:\n" << (large1^2) << std::endl;
    
    // דטרמיננטה של מטריצה 3x3
    std::cout << "Determinant of large1: " << !large1 << std::endl;
    
    // טרנספוזיציה
    std::cout << "Transpose of large1:\n" << ~large1 << std::endl;
    
    // כפל סקלרי במטריצה גדולה
    std::cout << "large1 * 0.5:\n" << large1 * 0.5 << std::endl;
    
    // אופרטורי השוואה למטריצות גדולות
    std::cout << "large1 == large2? " << (large1 == large2 ? "Yes" : "No") << std::endl;
    std::cout << "large1 > large2? " << (large1 > large2 ? "Yes" : "No") << std::endl;
    
    // דוגמה עם מטריצה 4x4
    std::cout << "\n===== 4x4 Matrix Example =====\n";
    
    SquareMat mat4(4);
    double val = 1.0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            mat4[i][j] = val++;
        }
    }
    
    std::cout << "4x4 Matrix:\n" << mat4 << std::endl;
    std::cout << "Determinant of 4x4 matrix: " << !mat4 << std::endl;
    
    return 0;
}