#include "command.h"
#include <string.h>
int main(int argc, char *argv[])
{
if (argc != 4) //���� ������������ ���-�� ����������
{
printf("Usage:\ncoder encode <in-file-name> <out-file-name>\ncoderdecode <in-file-name> <out-file-name>\n");
return 0;
}
else
{
if (!strcmp(argv[1], "decode")) //���� decode
{
decode_file(argv[2], argv[3]); //����������
}
else
{
if (!strcmp(argv[1], "encode")) //���� encode
{
encode_file(argv[2], argv[3]); //��������
}
else //���� ������������ �������
{
printf("Usage:\ncoder encode <in-file-name> <out-filename>\ncoder decode <in-file-name> <out-file-name>\n");
return 0;
}
}
}
return 0;
}
