\Problem name: 

Minimize
obj: Y
Subject To
LimCreditos_0:  X(0,0) + 0.50000 X(1,0) + X(2,0) + X(3,0) + X(4,0) + X(5,0) + X(6,0) + X(7,0) + X(8,0) + X(9,0)
 + X(10,0) + X(11,0) <= 5
LimCreditos_1:  X(0,1) + 0.50000 X(1,1) + X(2,1) + X(3,1) + X(4,1) + X(5,1) + X(6,1) + X(7,1) + X(8,1) + X(9,1)
 + X(10,1) + X(11,1) <= 5
LimCreditos_2:  X(0,2) + 0.50000 X(1,2) + X(2,2) + X(3,2) + X(4,2) + X(5,2) + X(6,2) + X(7,2) + X(8,2) + X(9,2)
 + X(10,2) + X(11,2) <= 5
LimCreditos_3:  X(0,3) + 0.50000 X(1,3) + X(2,3) + X(3,3) + X(4,3) + X(5,3) + X(6,3) + X(7,3) + X(8,3) + X(9,3)
 + X(10,3) + X(11,3) <= 5
LimCreditos_4:  X(0,4) + 0.50000 X(1,4) + X(2,4) + X(3,4) + X(4,4) + X(5,4) + X(6,4) + X(7,4) + X(8,4) + X(9,4)
 + X(10,4) + X(11,4) <= 5
Obrigatorias_4:  X(4,0) + X(4,1) + X(4,2) + X(4,3) + X(4,4) = 1
Obrigatorias_5:  X(5,0) + X(5,1) + X(5,2) + X(5,3) + X(5,4) = 1
Obrigatorias_6:  X(6,0) + X(6,1) + X(6,2) + X(6,3) + X(6,4) = 1
Obrigatorias_7:  X(7,0) + X(7,1) + X(7,2) + X(7,3) + X(7,4) = 1
Obrigatorias_8:  X(8,0) + X(8,1) + X(8,2) + X(8,3) + X(8,4) = 1
Obrigatorias_9:  X(9,0) + X(9,1) + X(9,2) + X(9,3) + X(9,4) = 1
Obrigatorias_10:  X(10,0) + X(10,1) + X(10,2) + X(10,3) + X(10,4) = 1
Obrigatorias_11:  X(11,0) + X(11,1) + X(11,2) + X(11,3) + X(11,4) = 1
PreReq_4_2:  - X(2,1) -2 X(2,2) -3 X(2,3) -4 X(2,4) + X(4,1) + 2 X(4,2) + 3 X(4,3) + 4 X(4,4) >= 1
PreReq_5_2:  - X(2,1) -2 X(2,2) -3 X(2,3) -4 X(2,4) + X(5,1) + 2 X(5,2) + 3 X(5,3) + 4 X(5,4) >= 1
PreReq_8_1:  - X(1,1) -2 X(1,2) -3 X(1,3) -4 X(1,4) + X(8,1) + 2 X(8,2) + 3 X(8,3) + 4 X(8,4) >= 1
PreReq_9_0:  - X(0,1) -2 X(0,2) -3 X(0,3) -4 X(0,4) + X(9,1) + 2 X(9,2) + 3 X(9,3) + 4 X(9,4) >= 1
PreReq_10_7:  - X(7,1) -2 X(7,2) -3 X(7,3) -4 X(7,4) + X(10,1) + 2 X(10,2) + 3 X(10,3) + 4 X(10,4) >= 1
PreReq_11_4:  - X(4,1) -2 X(4,2) -3 X(4,3) -4 X(4,4) + X(11,1) + 2 X(11,2) + 3 X(11,3) + 4 X(11,4) >= 1
Choq_Horario_0_0_6:  X(0,0) + X(6,0) <= 1
Choq_Horario_0_0_11:  X(0,0) + X(11,0) <= 1
Choq_Horario_0_2_4:  X(2,0) + X(4,0) <= 1
Choq_Horario_0_2_9:  X(2,0) + X(9,0) <= 1
Choq_Horario_0_4_2:  X(2,0) + X(4,0) <= 1
Choq_Horario_0_4_9:  X(4,0) + X(9,0) <= 1
Choq_Horario_0_6_0:  X(0,0) + X(6,0) <= 1
Choq_Horario_0_6_11:  X(6,0) + X(11,0) <= 1
Choq_Horario_0_9_2:  X(2,0) + X(9,0) <= 1
Choq_Horario_0_9_4:  X(4,0) + X(9,0) <= 1
Choq_Horario_0_11_0:  X(0,0) + X(11,0) <= 1
Choq_Horario_0_11_6:  X(6,0) + X(11,0) <= 1
Choq_Horario_1_0_6:  X(0,1) + X(6,1) <= 1
Choq_Horario_1_0_11:  X(0,1) + X(11,1) <= 1
Choq_Horario_1_2_4:  X(2,1) + X(4,1) <= 1
Choq_Horario_1_2_9:  X(2,1) + X(9,1) <= 1
Choq_Horario_1_4_2:  X(2,1) + X(4,1) <= 1
Choq_Horario_1_4_9:  X(4,1) + X(9,1) <= 1
Choq_Horario_1_6_0:  X(0,1) + X(6,1) <= 1
Choq_Horario_1_6_11:  X(6,1) + X(11,1) <= 1
Choq_Horario_1_9_2:  X(2,1) + X(9,1) <= 1
Choq_Horario_1_9_4:  X(4,1) + X(9,1) <= 1
Choq_Horario_1_11_0:  X(0,1) + X(11,1) <= 1
Choq_Horario_1_11_6:  X(6,1) + X(11,1) <= 1
Choq_Horario_2_0_6:  X(0,2) + X(6,2) <= 1
Choq_Horario_2_0_11:  X(0,2) + X(11,2) <= 1
Choq_Horario_2_2_4:  X(2,2) + X(4,2) <= 1
Choq_Horario_2_2_9:  X(2,2) + X(9,2) <= 1
Choq_Horario_2_4_2:  X(2,2) + X(4,2) <= 1
Choq_Horario_2_4_9:  X(4,2) + X(9,2) <= 1
Choq_Horario_2_6_0:  X(0,2) + X(6,2) <= 1
Choq_Horario_2_6_11:  X(6,2) + X(11,2) <= 1
Choq_Horario_2_9_2:  X(2,2) + X(9,2) <= 1
Choq_Horario_2_9_4:  X(4,2) + X(9,2) <= 1
Choq_Horario_2_11_0:  X(0,2) + X(11,2) <= 1
Choq_Horario_2_11_6:  X(6,2) + X(11,2) <= 1
Choq_Horario_3_0_6:  X(0,3) + X(6,3) <= 1
Choq_Horario_3_0_11:  X(0,3) + X(11,3) <= 1
Choq_Horario_3_2_4:  X(2,3) + X(4,3) <= 1
Choq_Horario_3_2_9:  X(2,3) + X(9,3) <= 1
Choq_Horario_3_4_2:  X(2,3) + X(4,3) <= 1
Choq_Horario_3_4_9:  X(4,3) + X(9,3) <= 1
Choq_Horario_3_6_0:  X(0,3) + X(6,3) <= 1
Choq_Horario_3_6_11:  X(6,3) + X(11,3) <= 1
Choq_Horario_3_9_2:  X(2,3) + X(9,3) <= 1
Choq_Horario_3_9_4:  X(4,3) + X(9,3) <= 1
Choq_Horario_3_11_0:  X(0,3) + X(11,3) <= 1
Choq_Horario_3_11_6:  X(6,3) + X(11,3) <= 1
Choq_Horario_4_0_6:  X(0,4) + X(6,4) <= 1
Choq_Horario_4_0_11:  X(0,4) + X(11,4) <= 1
Choq_Horario_4_2_4:  X(2,4) + X(4,4) <= 1
Choq_Horario_4_2_9:  X(2,4) + X(9,4) <= 1
Choq_Horario_4_4_2:  X(2,4) + X(4,4) <= 1
Choq_Horario_4_4_9:  X(4,4) + X(9,4) <= 1
Choq_Horario_4_6_0:  X(0,4) + X(6,4) <= 1
Choq_Horario_4_6_11:  X(6,4) + X(11,4) <= 1
Choq_Horario_4_9_2:  X(2,4) + X(9,4) <= 1
Choq_Horario_4_9_4:  X(4,4) + X(9,4) <= 1
Choq_Horario_4_11_0:  X(0,4) + X(11,4) <= 1
Choq_Horario_4_11_6:  X(6,4) + X(11,4) <= 1
Periodos_Neces_0_0:  - Y <= 0
Periodos_Neces_0_1:  - Y + X(0,1) <= 0
Periodos_Neces_0_2:  - Y + 2 X(0,2) <= 0
Periodos_Neces_0_3:  - Y + 3 X(0,3) <= 0
Periodos_Neces_0_4:  - Y + 4 X(0,4) <= 0
Periodos_Neces_1_0:  - Y <= 0
Periodos_Neces_1_1:  - Y + X(1,1) <= 0
Periodos_Neces_1_2:  - Y + 2 X(1,2) <= 0
Periodos_Neces_1_3:  - Y + 3 X(1,3) <= 0
Periodos_Neces_1_4:  - Y + 4 X(1,4) <= 0
Periodos_Neces_2_0:  - Y <= 0
Periodos_Neces_2_1:  - Y + X(2,1) <= 0
Periodos_Neces_2_2:  - Y + 2 X(2,2) <= 0
Periodos_Neces_2_3:  - Y + 3 X(2,3) <= 0
Periodos_Neces_2_4:  - Y + 4 X(2,4) <= 0
Periodos_Neces_3_0:  - Y <= 0
Periodos_Neces_3_1:  - Y + X(3,1) <= 0
Periodos_Neces_3_2:  - Y + 2 X(3,2) <= 0
Periodos_Neces_3_3:  - Y + 3 X(3,3) <= 0
Periodos_Neces_3_4:  - Y + 4 X(3,4) <= 0
Periodos_Neces_4_0:  - Y <= 0
Periodos_Neces_4_1:  - Y + X(4,1) <= 0
Periodos_Neces_4_2:  - Y + 2 X(4,2) <= 0
Periodos_Neces_4_3:  - Y + 3 X(4,3) <= 0
Periodos_Neces_4_4:  - Y + 4 X(4,4) <= 0
Periodos_Neces_5_0:  - Y <= 0
Periodos_Neces_5_1:  - Y + X(5,1) <= 0
Periodos_Neces_5_2:  - Y + 2 X(5,2) <= 0
Periodos_Neces_5_3:  - Y + 3 X(5,3) <= 0
Periodos_Neces_5_4:  - Y + 4 X(5,4) <= 0
Periodos_Neces_6_0:  - Y <= 0
Periodos_Neces_6_1:  - Y + X(6,1) <= 0
Periodos_Neces_6_2:  - Y + 2 X(6,2) <= 0
Periodos_Neces_6_3:  - Y + 3 X(6,3) <= 0
Periodos_Neces_6_4:  - Y + 4 X(6,4) <= 0
Periodos_Neces_7_0:  - Y <= 0
Periodos_Neces_7_1:  - Y + X(7,1) <= 0
Periodos_Neces_7_2:  - Y + 2 X(7,2) <= 0
Periodos_Neces_7_3:  - Y + 3 X(7,3) <= 0
Periodos_Neces_7_4:  - Y + 4 X(7,4) <= 0
Periodos_Neces_8_0:  - Y <= 0
Periodos_Neces_8_1:  - Y + X(8,1) <= 0
Periodos_Neces_8_2:  - Y + 2 X(8,2) <= 0
Periodos_Neces_8_3:  - Y + 3 X(8,3) <= 0
Periodos_Neces_8_4:  - Y + 4 X(8,4) <= 0
Periodos_Neces_9_0:  - Y <= 0
Periodos_Neces_9_1:  - Y + X(9,1) <= 0
Periodos_Neces_9_2:  - Y + 2 X(9,2) <= 0
Periodos_Neces_9_3:  - Y + 3 X(9,3) <= 0
Periodos_Neces_9_4:  - Y + 4 X(9,4) <= 0
Periodos_Neces_10_0:  - Y <= 0
Periodos_Neces_10_1:  - Y + X(10,1) <= 0
Periodos_Neces_10_2:  - Y + 2 X(10,2) <= 0
Periodos_Neces_10_3:  - Y + 3 X(10,3) <= 0
Periodos_Neces_10_4:  - Y + 4 X(10,4) <= 0
Periodos_Neces_11_0:  - Y <= 0
Periodos_Neces_11_1:  - Y + X(11,1) <= 0
Periodos_Neces_11_2:  - Y + 2 X(11,2) <= 0
Periodos_Neces_11_3:  - Y + 3 X(11,3) <= 0
Periodos_Neces_11_4:  - Y + 4 X(11,4) <= 0
Y:  Y >= 0
Bounds
 1 <= Y <= 10
 0 <= X(0,0) <= 1
 0 <= X(0,1) <= 1
 0 <= X(0,2) <= 1
 0 <= X(0,3) <= 1
 0 <= X(0,4) <= 1
 0 <= X(1,0) <= 1
 0 <= X(1,1) <= 1
 0 <= X(1,2) <= 1
 0 <= X(1,3) <= 1
 0 <= X(1,4) <= 1
 0 <= X(2,0) <= 1
 0 <= X(2,1) <= 1
 0 <= X(2,2) <= 1
 0 <= X(2,3) <= 1
 0 <= X(2,4) <= 1
 0 <= X(3,0) <= 1
 0 <= X(3,1) <= 1
 0 <= X(3,2) <= 1
 0 <= X(3,3) <= 1
 0 <= X(3,4) <= 1
 0 <= X(4,0) <= 1
 0 <= X(4,1) <= 1
 0 <= X(4,2) <= 1
 0 <= X(4,3) <= 1
 0 <= X(4,4) <= 1
 0 <= X(5,0) <= 1
 0 <= X(5,1) <= 1
 0 <= X(5,2) <= 1
 0 <= X(5,3) <= 1
 0 <= X(5,4) <= 1
 0 <= X(6,0) <= 1
 0 <= X(6,1) <= 1
 0 <= X(6,2) <= 1
 0 <= X(6,3) <= 1
 0 <= X(6,4) <= 1
 0 <= X(7,0) <= 1
 0 <= X(7,1) <= 1
 0 <= X(7,2) <= 1
 0 <= X(7,3) <= 1
 0 <= X(7,4) <= 1
 0 <= X(8,0) <= 1
 0 <= X(8,1) <= 1
 0 <= X(8,2) <= 1
 0 <= X(8,3) <= 1
 0 <= X(8,4) <= 1
 0 <= X(9,0) <= 1
 0 <= X(9,1) <= 1
 0 <= X(9,2) <= 1
 0 <= X(9,3) <= 1
 0 <= X(9,4) <= 1
 0 <= X(10,0) <= 1
 0 <= X(10,1) <= 1
 0 <= X(10,2) <= 1
 0 <= X(10,3) <= 1
 0 <= X(10,4) <= 1
 0 <= X(11,0) <= 1
 0 <= X(11,1) <= 1
 0 <= X(11,2) <= 1
 0 <= X(11,3) <= 1
 0 <= X(11,4) <= 1
Integers
Y X(0,0) X(0,1) X(0,2) X(0,3) X(0,4) X(1,0) X(1,1) X(1,2) X(1,3) 
X(1,4) X(2,0) X(2,1) X(2,2) X(2,3) X(2,4) X(3,0) X(3,1) X(3,2) X(3,3) 
X(3,4) X(4,0) X(4,1) X(4,2) X(4,3) X(4,4) X(5,0) X(5,1) X(5,2) X(5,3) 
X(5,4) X(6,0) X(6,1) X(6,2) X(6,3) X(6,4) X(7,0) X(7,1) X(7,2) X(7,3) 
X(7,4) X(8,0) X(8,1) X(8,2) X(8,3) X(8,4) X(9,0) X(9,1) X(9,2) X(9,3) 
X(9,4) X(10,0) X(10,1) X(10,2) X(10,3) X(10,4) X(11,0) X(11,1) X(11,2) X(11,3) 
X(11,4) 
End
