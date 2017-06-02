#pragma pack(push, 1)

typedef struct bmHeader
{
   unsigned short signature; //���������� ��� �����. ����� �� ������ ���� BM.
   unsigned int fileSize; //������ ������ ����� � ������
   unsigned short Reserved1; //�������������� � ������ ���� �����
   unsigned short Reserved2; //�������������� � ������ ���� �����
   unsigned int offsetToPixels; /*����������, ��� ���������� ��� ������� ������ ������������ ������ �����
   (��� �� ������ ��������� BITMAPFILEHEADER), ������� � ��������� ��������*/
} bmHeader;

typedef struct DIBheader
{
   unsigned int DIBSize; //������ ����� ���������
   unsigned int width; //������ ������ �������� � ��������
   unsigned int height; //������ ������ �������� � ��������
   unsigned short planes; //������ ���������� ����������, ���� ��� ������ ��������������� � 1
   unsigned short bitCount; //���������� ��� �� ���� �������
   unsigned int compression; //��� ������, ���� ������ ���, �� ���� ���� ���� ������������� � BI_RGB
   unsigned int sizeImage; /*���������� ������ �������� � ������, e��� ����������� �������
   (�� ���� ���������� ���� ����������� � BI_RGB), �� ����� ������ ���� ������� ����*/
   unsigned int xPixPerMeter; /*�������������� ���������� (� �������� �� ����) ��������� ����������,
   �� ������� ����� ���������� ������� ������ (�����)*/
   unsigned int yPixPerMeter; /*������������ ���������� (� �������� �� ����) ��������� ����������,
   �� ������� ����� ���������� ������� ������ (�����)*/
   unsigned int colourUsed; //���������� ���������� ������������ ������ �� �������
   unsigned int colourImportant; /*��� ���������� ������ ������. ���������� ����� ������,
   ������� ���������� ��� ����, ����� ���������� �������.
   ���� ��� �������� ����� 0 (��� ��� ������ � ������), �� ��� ����� ��������� �������*/
} DIBheader;



typedef struct RGB
{
	char  Blue;
	char  Green;
	char  Red;
} RGB;
#pragma pack(pop)
