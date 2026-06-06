# STM32G031F8 評価F/W開発

## 開発環境

- コンパイラ: Clang (`st-arm-clang 19.1.6`) 
  - 最適化: debug
- ツールチェイン
  - CMake
  - STM32CubeMX
  - STM32CubeIDE (VSCode版)

## ピンアサイン

![alt text](doc/STM32G031F8P6_CubeMXピン設定_20260607.png)

## メモリ使用量

- Lチカとprintf()のみでのメモリ使用量

```shell
[build] Memory region         Used Size  Region Size  %age Used
[build]              RAM:        2144 B         8 KB     26.17%
[build]            FLASH:       16152 B        64 KB     24.65%
```
