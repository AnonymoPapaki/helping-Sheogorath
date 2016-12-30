
#define _int32 int
#define _byte unsigned char


typedef struct tag_bmp_t
{
	_int32 height;
	_int32 width;
	_byte *pixelBuff;

}bmp_t;

void bmp_read(const _byte *buf, _int32 szBuf, bmp_t *bmp);

//do not compile this//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *fp;
	char buf[1024];
	bmp_t bmp;
	int sz = 0;
	int testRed = 0;
	int testGreen = 0;
	fp = fopen("test.bmp", "rb");
	sz = fread(buf, 1, 1024, fp);
	fclose(fp);
	bmp_read(buf, sz, &bmp);

	testRed = *(int*)bmp.pixelBuff;
	testGreen = *(int*)&bmp.pixelBuff[3];

	return 0;
}
//////////////////////

void bmp_read(const _byte *buf, _int32 szBuf, bmp_t *bmp)
{
	if (buf[0] == 'B' && buf[1] == 'M')
	{
		bmp->pixelBuff = (*(buf + 10)) + buf;
		bmp->height = *((_int32*)(buf + 18));
		bmp->width = *((_int32*)(buf + 22));
	
	}
}