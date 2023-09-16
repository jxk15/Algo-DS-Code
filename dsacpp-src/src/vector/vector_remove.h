/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2023. All rights reserved.
 ******************************************************************************************/

#pragma once

template <typename T> T Vector<T>::remove( Rank r ) { //删除向量中秩为r的元素，0 <= r < size
   T e = _elem[r]; //备份被删除元素
   remove( r, r + 1 ); //调用区间删除算法，等效于对区间[r, r + 1)的删除
   return e; //返回被删除元素
}

// template <typename T> Rank Vector<T>::remove( Rank lo, Rank hi ) { // 0 <= lo <= hi <= n
//    if ( lo == hi ) return 0; // 出于效率考虑，单独处理退化情况
//    while ( hi < _size ) _elem[lo++] = _elem[hi++]; // 后缀[hi, _size)顺次前移hi-lo位
//    _size = lo;
//    shrink(); // 更新规模，lo=_size之后的内容无需清零；如必要，则缩容
//    // 若有必要，则缩容
//    return hi - lo; // 返回被删除元素的数目
// }