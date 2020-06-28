#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>
/*void showbits(unsigned int x)
{
for (int i = (sizeof(int) * 8) - 1; i >= 0; i--)
{
putchar(x & (1u << i) ? '1' : '0');
}
printf("\n");
}*/
enum
{
MaxCodeLength = 4
};
typedef struct
{
uint8_t code[MaxCodeLength];
size_t length;
} CodeUnit;
int encode(uint32_t code_point, CodeUnit *code_units)
{
int count = 0;
uint32_t c = code_point;
while (c) //������� ���-�� ����� � �����
{
c >>= 1;
count++;
}
if (count < 8)
{
code_units->length = 1;
code_units->code[0] = 0x7f & code_point;
}
else
{
code_units->length = (count + 3) % 5; //���-�� ���� ��������������� �����
if (code_units->length > 4)
{
return -1;
}
size_t i;
int mask = 8 - code_units->length;//���-�����, �� ������� ����� �������� ��� ������� �����
code_units->code[0] = pow(2, code_units->length) - 1; //����������������� ������� ��� ������� �����
code_units->code[0] <<= mask; //��������� �� �� �����
for (i = code_units->length - 1; i > 0; i--)
{
code_units->code[i] = 0x80 | (code_point & 0x3f);
code_point >>= 6; //��������� ��������� �����
}
code_units->code[0] |= code_point; //���������� ���� ��������� ������� ������
}
return 0;
}
uint32_t decode(const CodeUnit *code_unit)
{
uint32_t dec = 0;
if (code_unit->length == 1) //���� ����� 1, �� �������������� �����== ���������
{
dec = code_unit->code[0];
}
else
{
if (code_unit->length == 2)
{
dec = code_unit->code[0] & 0x1f; //������� ��������� ��������������
dec <<= 6;
dec |= (0x3f & code_unit->code[1]); //���������� ������ ����
}
else
{
if (code_unit->length == 3)
{
size_t i;
dec = code_unit->code[0] & 0xf; //������� ���������������� �������
for (i = 1; i < code_unit->length; i++)
{
dec <<= 6;
dec |= (0x3f & code_unit->code[i]); //������������������� ����� ����
}
}
else
{
size_t i;
dec = code_unit->code[0] & 0x7; //������� ���������������� �������
for (i = 1; i < code_unit->length; i++)
{
dec <<= 6;
dec |= (0x3f & code_unit->code[i]); //������������������� ����� ����
}
}
}
}
return dec;
}
int write_code_unit(FILE *out, const CodeUnit *code_unit)
{
size_t i;
for (i = code_unit->length; i > 0; i--) //��������� ����������� ����
{
size_t count = fwrite(&code_unit->code[code_unit->length - i], 1,
sizeof(uint8_t), out);
if (count != sizeof(uint8_t))
{
return -1;
}
}
return 0;
}
int read_next_code_unit(FILE *in, CodeUnit *code_units)
{
uint8_t n[4];
code_units->length = 0;
size_t t = fread(&n[0], sizeof(uint8_t), 1, in); //��������� ����������
if (t != 1)
{
return -1;
}
if (n[0] >> 7 == 0) //���� ��������� ����� - 0
{
code_units->length = 1;
code_units->code[0] = n[0];
}
else
{
int i;
for (i = 5; i >= 3; i--)
{                                        //showbits(n[0]);
if (n[0] >> (8 - i) == (pow(2, i) - 2)) //���� ���� �� �����
{
int count = 0;
uint8_t y = n[0] >> (8 - i + 1);
while (y) //������� ���-�� �������������� ����
{
y >>= 1;
count++;
}
int j;
for (j = 1; j < count; j++)
{
size_t t = fread(&n[j], sizeof(uint8_t), 1, in);//��������� ��������� ����
if (!t)
{
return -1;
}
if (n[j] >> 6 != 2)
{
return read_next_code_unit(in, code_units);//���� ���� �����
}
}
for (j = 0; j < count; j++)
{
code_units->code[j] = n[j]; //���������� � ���������
}
code_units->length = count;
break;
}
}
}
if (code_units->length == 0) //���� �� ����� � ���� - ����� ����(10xxxxxx)
{
return read_next_code_unit(in, code_units);
}
return 0;
}
