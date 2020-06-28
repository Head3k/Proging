#include "coder.c"
#include <inttypes.h>
#include <stdlib.h>

int encode_file(const char *in_file_name, const char *out_file_name)
{
FILE *in = fopen(in_file_name, "r"); //��������� ���� �� ������
FILE *out = fopen(out_file_name, "wb"); //� �������� �� ������
if (!in)
{
fclose(out);
return -1;
}
if (!out)
{
fclose(in);
return -1;
}
CodeUnit *c = malloc(sizeof(CodeUnit));
uint32_t n;
while (!feof(in))
{
size_t k = fscanf(in, "%" SCNx32, &n); //��������� �� ����� �����
int t = encode(n, c); //�������� ���
int y = write_code_unit(out, c); //� ���������� � ��������
if (t || y || k != 1) //���� ���-�� ������
{
free(c);
fclose(in);
fclose(out);
return -1;
}
}
fclose(in);
fclose(out);
free(c);
return 0;
}
int decode_file(const char *in_file_name, const char *out_file_name)
{
FILE *in = fopen(in_file_name, "rb"); //��������� �������� �� ������
FILE *out = fopen(out_file_name, "w"); //� ���� �� ������
if (!in)
{
fclose(out);
return -1;
}
if (!out)
{
fclose(in);
return -1;
}
CodeUnit *c = malloc(sizeof(CodeUnit)); //�������� ������ ��� ���������
while (read_next_code_unit(in, c) != -1) //���� ��� ������ � �������
{
uint32_t dec = decode(c); //����������
size_t t = fprintf(out, "\n%" SCNx32, dec); //���������� � ����
if (!t) //���� ���-�� ������
{
free(c);
return -1;
}
}
free(c);
return 0;
}
