#include"StrCmp.h"

bool FindCmp(unsigned char* dsc, unsigned char* scr, int n)
{
	if (strncmp((char*)dsc, (char*)scr, n) == 0)
	{
		return true;
	}
	else
	{
		return false;

	}

}

int checkischinese(unsigned char* scr, int ppos, int pstrlen)
{
	unsigned char* p = (scr + ppos);
	for (int i = 0; i < pstrlen - 1; i++) {
		if (*p < 0x20 || *p >= 0x7F)
			return 1;
		p++;
	}
	return 0;
}

int FindAscii(unsigned char* scr, int n, int pstrlen, int* pretlen, int* pisunicode)
{
	unsigned char* p = scr;
	int iret = -1;
	int ilen = 0;
	int iascii = 0;
	__int64 lascii = 0;
	__int64 lasciirev = 0;
	bool bisunicode = false;
	for (int i = 0; i < n - 1; i++)
	{
		/*if((*p==0 || *p==0xFF) && ilen==0){
			p++;
			continue;
		}
		else {*/
		if (*p > 31 && *p < 127 && !bisunicode && (ilen < pstrlen && *(p + 1)>31 && *(p + 1) < 127 || ilen >= pstrlen - 1 && (*(p + 1) > 31 && *(p + 1) < 127 || *(p + 1) == 0)))
		{
			if (ilen == 0) {
				iret = i;
				bisunicode = false;
			}
			ilen++;
		}
		else if (*p == 0 && !bisunicode && ilen >= pstrlen) {
			//ilen++;
			*pretlen = ilen;
			*pisunicode = checkischinese(scr, iret, ilen);
			return iret;
		}
		else {
			if (*p == 0 && ilen > 1 && bisunicode) {
				if (*(p - 1) == 0) {
					if (ilen >= pstrlen) {
						*pretlen = ilen;
						*pisunicode = checkischinese(scr, iret, ilen);
						return iret;
					}
					else {
						ilen = 0;
						iret = -1;
						bisunicode = false;
						p++;
						continue;
					}
				}
			}
			lasciirev = ((*(p + 1)) << 8) + (*p);

			iascii = ((*p) << 8) + *(p + 1);
			if (*p == 1)
				lascii = ((*p) << 16) + ((*(p + 1)) << 8) + *(p + 2);
			else
				lascii = 0;
			//
			if ((iascii >= 0x00B0A1 && iascii <= 0x00D7F9) || (iascii >= 0x2E80 && iascii <= 0xA4CF) || (lasciirev >= 0x0020 && lasciirev <= 0x007f) || (lasciirev >= 0x00B0A1 && lasciirev <= 0x00D7F9 && (*p) >= 0x20) || ((*p > 0 || *p == 0 && ilen > 0) && *p < 0xFF && (*(p + 1) > 0x4d && *(p + 1) < 0xa0)) || (*p > 0 && *p < 0xA0 && *(p + 1) == 0xFF)) {
				if (ilen == 0)
					iret = i;
				ilen += 2;
				i++;
				p++;
				bisunicode = true;
			}
			else if ((lascii >= 0x014E00 && lascii <= 0x019FA5))
			{
				if (ilen == 0)
					iret = i;
				ilen += 3;
				i++;
				p++;
				i++;
				p++;

				bisunicode = true;
			}
			else if (ilen >= pstrlen && ilen > 0)
			{
				*pretlen = ilen;
				*pisunicode = checkischinese(scr, iret, ilen);
				/*if (bisunicode)
				*pisunicode=1;
				else
				*pisunicode=0;*/
				return iret;
			}
			else
			{
				ilen = 0;
				iret = -1;
				bisunicode = false;
			}
		}
		p++;
		//}
	}
	return -1;
}

int FindAsciiNext(unsigned char* scr, int n, int pstrlen, int ppos, int* pretlen, int* pisunicode)
{
	unsigned char* p = (scr + ppos);
	int iret = -1;
	int ilen = 0;
	int iascii = 0;
	__int64 lascii = 0;
	__int64 lasciirev = 0;
	bool bisunicode = false;
	for (int i = ppos; i < n - 1; i++)
	{
		/*if((*p==0 || *p==0xFF) && ilen==0){
			p++;
			continue;
		}
		else{*/
		if (*p > 31 && *p < 127 && !bisunicode && (ilen < pstrlen && *(p + 1)>31 && *(p + 1) < 127 || ilen >= pstrlen - 1 && (*(p + 1) > 31 && *(p + 1) < 127 || *(p + 1) == 0)))
		{
			if (ilen == 0) {
				iret = i;
				bisunicode = false;
			}
			ilen++;

		}
		else if (*p == 0 && !bisunicode && ilen >= pstrlen) {
			//ilen++;
			*pretlen = ilen;
			*pisunicode = checkischinese(scr, iret, ilen);
			return iret;
		}
		else {
			if (*p == 0 && ilen > 1 && bisunicode) {
				if (*(p - 1) == 0) {
					if (ilen >= pstrlen) {
						*pretlen = ilen;
						*pisunicode = checkischinese(scr, iret, ilen);
						return iret;
					}
					else {
						ilen = 0;
						iret = -1;
						bisunicode = false;
						p++;
						continue;
					}
				}
			}
			/*if (*p==0 && ilen>=pstrlen && !bisunicode ){
				*pretlen=ilen;
				*pisunicode=checkischinese(scr,iret,ilen);
				return iret;
			}*/
			lasciirev = ((*(p + 1)) << 8) + (*p);

			iascii = ((*p) << 8) + *(p + 1);
			if (*p == 1)
				lascii = ((*p) << 16) + ((*(p + 1)) << 8) + *(p + 2);
			else
				lascii = 0;
			//
			if ((iascii >= 0x00B0A1 && iascii <= 0x00D7F9) || (iascii >= 0x2E80 && iascii <= 0xA4CF) || (lasciirev >= 0x0020 && lasciirev <= 0x007f) || (lasciirev >= 0x00B0A1 && lasciirev <= 0x00D7F9 && (*p) >= 0x20) || ((*p > 0 || *p == 0 && ilen > 0) && *p < 0xFF && (*(p + 1) > 0x4d && *(p + 1) < 0xa0)) || (*p > 0 && *p < 0xA0 && *(p + 1) == 0xFF)) {
				if (ilen == 0)
					iret = i;
				ilen += 2;
				i++;
				p++;
				bisunicode = true;
			}
			else if ((lascii >= 0x014E00 && lascii <= 0x019FA5))
			{
				if (ilen == 0)
					iret = i;
				ilen += 3;
				i++;
				p++;
				i++;
				p++;

				bisunicode = true;
			}
			else if (ilen >= pstrlen && ilen > 0)
			{
				*pretlen = ilen;
				*pisunicode = checkischinese(scr, iret, ilen);
				/*if (bisunicode)
				*pisunicode=1;
				else
				*pisunicode=0;*/
				return iret;
			}
			else
			{
				ilen = 0;
				iret = -1;
				bisunicode = false;
			}
		}
		p++;
		//}
	}
	return -1;
}

int FindAsciiU(unsigned char* scr, int n, int pstrlen, int* pretlen)
{
	unsigned char* p = scr;
	int iret = -1;
	int ilen = 0;
	int iascii = 0;
	__int64 lascii = 0;
	__int64 lasciirev = 0;
	for (int i = 0; i < n - 1; i++)
	{
		iascii = ((*p) << 8) + *(p + 1);
		if (*p == 1)
			lascii = ((*p) << 16) + ((*(p + 1)) << 8) + *(p + 2);
		else
			lascii = 0;
		lasciirev = ((*(p + 1)) << 8) + (*p);
		//if ((iascii>=0x00B0A1 && iascii<0x00D7F9) || (iascii>=0x3000 && iascii<0x303f) || (iascii>=0x4E00 && iascii<0x9FA5) || (iascii>=0x2E80 && iascii<=0xA4CF) || (iascii>=0x00F900  && iascii<=0x00FAFF) || (iascii>=0x00FE30  && iascii<=0x00FE4F))
		//iascii>=0x2000 && iascii<=0x7F00) ||  (iascii>=0x3000 && iascii<0x303f) || (iascii>=0x00F900  && iascii<=0x00FAFF) || (iascii>=0x00FE30  && iascii<=0x00FE4F) ||
		if ((iascii >= 0x00B0A1 && iascii <= 0x00D7F9) || (lascii >= 0x014E00 && lascii <= 0x019FA5) || (iascii >= 0x2E80 && iascii <= 0xA4CF) ||
			(lasciirev >= 0x0020 && lasciirev <= 0x007f) || (lasciirev >= 0x00B0A1 && lasciirev <= 0x00D7F9 && *p >= 0x40) || ((*p > 0 || *p == 0 && ilen > 0) && *p < 0xFF && (*(p + 1) > 0x4d && *(p + 1) < 0xa0)) || (*p > 0 && *p < 0xA0 && *(p + 1) == 0xFF)) {
			if (ilen == 0)
				iret = i;
			ilen++;
			ilen++;
			i++;
			p++;
			if (lascii >= 0x014E00 && lascii <= 0x019FA5)
			{
				ilen++;
				i++;
				p++;
			}
		}
		else if (ilen >= pstrlen && ilen > 0)
		{
			*pretlen = ilen;
			return iret;
		}
		else
		{
			ilen = 0;
			iret = -1;
		}

		p++;
	}
	return -1;
}

int FindAsciiNextU(unsigned char* scr, int n, int pstrlen, int ppos, int* pretlen)
{
	unsigned char* p = (scr + ppos);
	int iret = -1;
	int ilen = 0;
	int iascii = 0;
	__int64 lascii = 0;
	__int64 lasciirev = 0;
	for (int i = ppos; i < n - 1; i++)
	{
		iascii = ((*p) << 8) + *(p + 1);
		if (*p == 1)
			lascii = ((*p) << 16) + ((*(p + 1)) << 8) + *(p + 2);
		else
			lascii = 0;
		lasciirev = ((*(p + 1)) << 8) + (*p);
		//if ((iascii>=0x2000 && iascii<=0x7F00) || (iascii>=0x00B0A1 && iascii<=0x00D7F9) || (iascii>=0x3000 && iascii<0x303f) || (lascii>=0x014E00 && lascii<=0x019FA5) || (iascii>=0x2E80 && iascii<=0xA4CF) || (iascii>=0x00F900  && iascii<=0x00FAFF) || (iascii>=0x00FE30  && iascii<=0x00FE4F))
		// (iascii>=0x00F900  && iascii<=0x00FAFF) || (iascii>=0x00FE30  && iascii<=0x00FE4F) ||
		if ((iascii >= 0x00B0A1 && iascii <= 0x00D7F9) || (lascii >= 0x014E00 && lascii <= 0x019FA5) || (iascii >= 0x2E80 && iascii <= 0xA4CF) ||
			(lasciirev >= 0x0020 && lasciirev <= 0x007f) || (lasciirev >= 0x00B0A1 && lasciirev <= 0x00D7F9 && *p >= 0x40) || ((*p > 0 || *p == 0 && ilen > 0) && *p < 0xFF && (*(p + 1) > 0x4d && *(p + 1) < 0xa0)) || (*p > 0 && *p < 0xA0 && *(p + 1) == 0xFF)) {
			if (ilen == 0)
				iret = i;
			ilen++;
			ilen++;
			i++;
			p++;
			if (lascii >= 0x014E00 && lascii <= 0x019FA5)
			{
				ilen++;
				i++;
				p++;
			}
		}
		else if (ilen >= pstrlen && ilen > 0)
		{
			*pretlen = ilen;
			return iret;
		}
		else
		{
			ilen = 0;
			iret = -1;
		}
		p++;
	}
	return -1;
}

int FindAsciiUtf8(unsigned char* scr, int n, int pstrlen, int* pretlen)
{
	unsigned char* p = scr;
	int iret = -1;
	int ilen = 0;
	//int iascii=0;
	//__int64 lascii=0;
	for (int i = 0; i < n - 1; i++)
	{
		//if ((iascii>=0x00B0A1 && iascii<0x00D7F9) || (iascii>=0x3000 && iascii<0x303f) || (iascii>=0x4E00 && iascii<0x9FA5) || (iascii>=0x2E80 && iascii<=0xA4CF) || (iascii>=0x00F900  && iascii<=0x00FAFF) || (iascii>=0x00FE30  && iascii<=0x00FE4F))
		if (*p > 31 && *p < 127)
		{
			if (ilen == 0)
				iret = i;
			ilen++;
		}
		else if (((*p) >> 2) >= 0x0B && ((*(p + 1)) >> 2) >= 8)
		{
			if (ilen == 0)
				iret = i;
			ilen++;
			ilen++;
			i++;
			p++;
		}
		else if (((*p) >> 2) >= 0x0E && ((*(p + 1)) >> 2) >= 8 && ((*(p + 2)) >> 2) >= 8)
		{
			if (ilen == 0)
				iret = i;
			ilen += 3;
			i += 2;
			p++;
			p++;
		}
		else if (ilen >= pstrlen && ilen > 0)
		{
			*pretlen = ilen;
			return iret;
		}
		else
		{
			ilen = 0;
			iret = -1;
		}

		p++;
	}
	return -1;
}

int FindAsciiNextUtf8(unsigned char* scr, int n, int pstrlen, int ppos, int* pretlen)
{
	unsigned char* p = (scr + ppos);
	int iret = -1;
	int ilen = 0;
	//int iascii=0;
	//__int64 lascii=0;
	for (int i = ppos; i < n - 1; i++)
	{
		if (*p > 31 && *p < 127)
		{
			if (ilen == 0)
				iret = i;
			ilen++;
		}
		else if (((*p) >> 2) >= 0x0B && ((*(p + 1)) >> 2) >= 8)
		{
			if (ilen == 0)
				iret = i;
			ilen++;
			ilen++;
			i++;
			p++;
		}
		else if (((*p) >> 2) >= 0x0E && ((*(p + 1)) >> 2) >= 8 && ((*(p + 2)) >> 2) >= 8)
		{
			if (ilen == 0)
				iret = i;
			ilen += 3;
			i += 2;
			p++;
			p++;
		}
		else if (ilen >= pstrlen && ilen > 0)
		{
			*pretlen = ilen;
			return iret;
		}
		else
		{
			ilen = 0;
			iret = -1;
		}
		p++;
	}
	return -1;
}