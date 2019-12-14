#ifndef OUTPUT_H
#define OUTPUT_H
/*

Test Stack
s H->[9]-> [8]-> [7]-> [6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
s2H->[9]-> [8]-> [7]-> [6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
 after s pop
{9}H->[8]-> [7]-> [6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
{8}H->[7]-> [6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
{7}H->[6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
{6}H->[5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
{5}H->[4]-> [3]-> [2]-> [1]-> [0]-> |||
{4}H->[3]-> [2]-> [1]-> [0]-> |||
{3}H->[2]-> [1]-> [0]-> |||
{2}H->[1]-> [0]-> |||
{1}H->[0]-> |||
{0}H->|||
assign s back to s2
s H->[9]-> [8]-> [7]-> [6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||
s2H->[9]-> [8]-> [7]-> [6]-> [5]-> [4]-> [3]-> [2]-> [1]-> [0]-> |||


Queue Test
q H->[0]-> [1]-> [2]-> [3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
q2H->[0]-> [1]-> [2]-> [3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
 after q pop
{0}H->[1]-> [2]-> [3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
{1}H->[2]-> [3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
{2}H->[3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
{3}H->[4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
{4}H->[5]-> [6]-> [7]-> [8]-> [9]-> |||
{5}H->[6]-> [7]-> [8]-> [9]-> |||
{6}H->[7]-> [8]-> [9]-> |||
{7}H->[8]-> [9]-> |||
{8}H->[9]-> |||
{9}H->|||
assign q back to q2
q H->[0]-> [1]-> [2]-> [3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||
q2H->[0]-> [1]-> [2]-> [3]-> [4]-> [5]-> [6]-> [7]-> [8]-> [9]-> |||


*/
#endif // OUTPUT_H
