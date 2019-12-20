#ifndef TOOL_H_
#define TOOL_H_
#include <mainwindow.h>

#define APP_SUCC    (0)   /*�ɹ�      */
#define APP_FAIL    -1    /*ʧ��      */
#define APP_QUIT    -2    /*�˳���ȡ��*/
#define APP_TIMEOUT -3    /*��ʱ  */


#define PubSelectList(pstr, pstitle, nselect, pnselect) \
        PubSelectListItem( pstr, pstitle, NULL, nselect, pnselect)

#define	ERR_TOOL_BASE			(-3400)
#define	ERR_TOOL_SOURCE		ERR_TOOL_BASE -1	/*Դ��Ϊ�ջ�Ƿ��ַ���*/
#define	ERR_TOOL_TARGET		ERR_TOOL_BASE -2	/*Ŀ�껺�����ռ䲻��*/
#define	ERR_TOOL_CHECK		ERR_TOOL_BASE -3	/*У��ʧ��*/
#define	ERR_TOOL_BACKTYPE	ERR_TOOL_BASE -4	/*������Ϣ���ʹ���*/
#define	ERR_TOOL_TIMEOUT	ERR_TOOL_BASE -5	/*��ʱ���ް���*/
#define ERR_TOOL_API		ERR_TOOL_BASE -6	/*�ײ�API���ش���*/
#define ERR_TOOL_DIRECTION	ERR_TOOL_BASE -7	/*����ģʽ����*/
#define POS_MAIN_KEY        99//��ȡ����Կ
#define POS_WORK_PIN_KEY    98//��ȡPIN��Կ
#define POS_WORK_MAC_KEY    97//��ȡMAC��Կ

//��ȡMD5��
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define RL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
//x����ѭ����yλ
#define PP(x) (x<<24)|((x<<8)&0xff0000)|((x>>8)&0xff00)|(x>>24)
//��x�ߵ�λ����,����PP(aabbccdd)=ddccbbaa
#define FF(a, b, c, d, x, s, ac) a = b + (RL((a + F(b,c,d) + x + ac),s))
#define GG(a, b, c, d, x, s, ac) a = b + (RL((a + G(b,c,d) + x + ac),s))
#define HH(a, b, c, d, x, s, ac) a = b + (RL((a + H(b,c,d) + x + ac),s))
#define II(a, b, c, d, x, s, ac) a = b + (RL((a + I(b,c,d) + x + ac),s))

#ifdef USE_POS_INSIDE_PINPAD
int PubCalcEsamUnlockValue(char *);
#endif


#define APP_SUCC    (0)   /*�ɹ�      */
#define APP_FAIL    -1  /*ʧ��      */

#define ENCRYPT 0
#define DECRYPT 1
#define PARAMERR 2

#define   x99                  0
#define   PBOC_Des_Mac         1
#define   PBOC_3Des_Mac        2

//��ȡMD5��
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define RL(x, y) (((x) << (y)) | ((x) >> (32 - (y)))) 
//x����ѭ����yλ
#define PP(x) (x<<24)|((x<<8)&0xff0000)|((x>>8)&0xff00)|(x>>24)  
//��x�ߵ�λ����,����PP(aabbccdd)=ddccbbaa
#define FF(a, b, c, d, x, s, ac) a = b + (RL((a + F(b,c,d) + x + ac),s))
#define GG(a, b, c, d, x, s, ac) a = b + (RL((a + G(b,c,d) + x + ac),s))
#define HH(a, b, c, d, x, s, ac) a = b + (RL((a + H(b,c,d) + x + ac),s))
#define II(a, b, c, d, x, s, ac) a = b + (RL((a + I(b,c,d) + x + ac),s))

extern unsigned char  Mout[8];


typedef struct
{
    char szMenuName[32];		/*�˵�����*/
    int nMenuID;		        /*��Ӧ�Ĺ���ID*/
    int nMenuDepth;			/*�˵�����*/
    int nShortcutKey;			/*��ݼ�*/
    int nIsVisible;		        /*��ǰ�˵��Ƿ�ɼ�*/
} STMENU_RESOURCE_EXTERN;


typedef struct
{
    char szMenuName[32];		        /*�˵�����*/
    int nMenuID;				/*��Ӧ�Ĺ���ID*/
    int nIsVisible;				/*��ǰ�˵��Ƿ�ɼ�*/
} MENU_ITEM;


typedef struct
{
  unsigned short  length;
  unsigned char  *value;
}RowData; /*used for data exchange */

typedef struct
{
	unsigned char sourceLen;
	unsigned char sourceData[200];
	
	unsigned char encryptedLen;
  unsigned char encryptedData[200];
}Encrypt_Data;

typedef struct
{
	unsigned char sourceLen;
	unsigned char sourceData[200];
	unsigned char initData[8];
  unsigned char MACData[4];
}CalcMAC_Data;


//�㷨��ʶ 0-des 1-3des
typedef enum
{
	DES_ENCY,
	DES3_ENCY
}AlgorIdent;

typedef enum
{
  MAC2_ERR,
	MAC2_RIGHT
}mac_en;

unsigned char EncryptionData(Encrypt_Data *inputdata, unsigned char *key, unsigned char keylen);

unsigned char CalculateMAC_Data(CalcMAC_Data *inputdata, unsigned char *key, unsigned char *keylen);

unsigned char test_Pro_PSAMCreatDFExKey(void) ;

unsigned char Data_Encryption(unsigned char inputlen,   //�������ݳ���
                               unsigned char *inputbuf, //�������ݿ�
                               unsigned char *outdLen,  //���ص����ݳ���
                               unsigned char *outData,  //���صļ������ݿ�
                               unsigned char *key,      //������Կ
                               AlgorIdent Algortype);   //0-des 1-3des

void Data_MAC(  unsigned char  *initdata, //MAC��ʼ������
								unsigned char  *inputbuf, //�������ݿ�
								int            buf_size,  //���ݿ鳤��
								unsigned char  *key,      //MAC ��Կ 
								unsigned char  *mac_buf,  //�����MAC���� 
								unsigned char  Keytype);  //��Կ����

unsigned char AmountFormString(unsigned long value,unsigned char *Amountstr);
int  GetPanFormTrace(unsigned char *szPan, unsigned char *panlen, unsigned char *expdata, const unsigned char *szTk2, const unsigned char *szTk3);

//unsigned char HexToSerialBCD( unsigned char *hexSrc, unsigned char *BcdDes, unsigned int num ,unsigned char mode);

void GetRandom(unsigned char *random,unsigned char randomlen);
int PubHexToAsc (const unsigned char* pszBcdBuf, int nLen, char cType, unsigned char* pszAsciiBuf);
unsigned char CardSNFormSting(unsigned char SN,unsigned char *SNstr);

int PubAddDigitStr (const char* pszDigStr1, const char* pszDigStr2, char* pszResult, int* pnResultLen );
int PubPrintData (const char* pcData, int nLen );
int PubIncNum (char* pcStrNum );
int PubGetPosType (int* nPosTypeFlag );
int PubFmtAmtStr (const char* pszSource, char* pszTarget, int* pnTargetLen );

int PubSoftDES (int nDirection, unsigned char* psKey,
                       unsigned char* psText, unsigned char* psResult );
int PubSoftTriDES (int nDirection,unsigned char* psKey,
                          unsigned char* psText, unsigned char* psResult );
int  PubAscToHex (const unsigned char* pszAsciiBuf, int nLen, char cType, unsigned char* pszBcdBuf);
int  PubHexToAsc (const unsigned char* pszBcdBuf, int nLen, char cType, unsigned char* pszAsciiBuf);
void PubIntToC4 (unsigned char* pszBuf, unsigned int nNum );
void PubIntToC2 (unsigned char* pszBuf, unsigned int nNum );
void PubC4ToInt (unsigned int* nNum, unsigned char * pszBuf );

void PubC2ToInt(unsigned int *nNum, unsigned char *pszBuf);
int  PubBcdToInt(const char * psBcd, int *nNum);

int  PubCalcLRC(const char *psBuf, int nLen, char *chLRC);

void PubLeftTrim(char *pszSrc);
void PubRightTrim(char *pszSrc);
void PubAllTrim(char *pszSrc);
int  PubAddSymbolToStr(char *pszString, int nLen, char ch, int nOption);
int  PubSubStr(const char *pszSouStr, int nStartPos, int nNum, char *pszObjStr, int *pnObjStrLen);
int  PubIsDigitStr(const char *pszString);
int  PubIsDigitChar(char ch);
int  PubIsValidDate(const char *pDate);
void PubGetCurrentDatetime(char *pDatetime);
int  PubMonthDays(int nYear, int nMon, int *pnDays);
int  PubIsLeapYear(int nYear);
void PubGetLibVer(char *pszVer);
int  PubGetErrCode(void);
void PubInitPubLib(void);
int PubGetCPLDInfo(char* pszCpldVer);

int PubAddDigitStr (const char* pszDigStr1, const char* pszDigStr2, char* pszResult, int* pnResultLen );
int PubDispData (const unsigned char* pcData, int nLen );
void unDes(const unsigned char szInput[8], unsigned char szOutput[8], const unsigned char szDesKey[8]);
int qdes(unsigned char *source,unsigned char * dest,unsigned char * inkey, int flg);
int qdes3(unsigned char *source,unsigned char * dest,unsigned char * inkey, int flg);
int PubHexToAsc (const unsigned char* pszBcdBuf, int nLen, char cType, unsigned char* pszAsciiBuf);
//int PubAscToHex (const unsigned char* pszAsciiBuf, int nLen, char cType, unsigned char* pszBcdBuf);


void PubIntToC4 (unsigned char* pszBuf, unsigned int nNum );
void PubIntToC2 (unsigned char* pszBuf, unsigned int nNum );
void PubC4ToInt (unsigned int* nNum, unsigned char * pszBuf );
void PubC2ToInt(unsigned int *nNum, unsigned char *pszBuf);
int  PubByteToBcd(int nNum, unsigned char *ch);
int  PubBcdToByte(unsigned char ch, int *pnNum);

int  PubIntToBcd(unsigned char *psBcd, int *pnBcdLen, int nNum);

int  GetMD5Code(char *pszInBuf, int nLen, char *pszOutBuf);

int PubInPutDlg(char *pszBuf);
int TestAllKey(void);

int CRCcount(char *ccInput, int ccLen, char *ccOut);
int CRCcompare(char *cmInput, int cmLen, char *cmData);

int  PubBcdToInt(const char * psBcd, int *nNum);

int  PubCalcLRC(const char *psBuf, int nLen, char *chLRC);


int PubPrintData (const char* pcData, int nLen );
int PubIncNum (char* pcStrNum );
int PubGetPosType (int* nPosTypeFlag );
int PubFmtAmtStr (const char* pszSource, char* pszTarget, int* pnTargetLen );

int PubSoftDES (int nDirection, unsigned char* psKey,
                       unsigned char* psText, unsigned char* psResult );
int PubSoftTriDES (int nDirection,unsigned char* psKey,
                          unsigned char* psText, unsigned char* psResult );
//int PubAscToHex (const unsigned char* pszAsciiBuf, int nLen, char cType, unsigned char* pszBcdBuf);
int PubHexToAsc (const unsigned char* pszBcdBuf, int nLen, char cType, unsigned char* pszAsciiBuf);

void PubLeftTrim(char *pszSrc);
void PubRightTrim(char *pszSrc);
void PubAllTrim(char *pszSrc);
int  PubAddSymbolToStr(char *pszString, int nLen, char ch, int nOption);
int  PubSubStr(const char *pszSouStr, int nStartPos, int nNum, char *pszObjStr, int *pnObjStrLen);
int  PubIsDigitStr(const char *pszString);
int  PubIsDigitChar(char ch);
int  PubIsValidDate(const char *pDate);
void PubGetCurrentDatetime(char *pDatetime);
int  PubMonthDays(int nYear, int nMon, int *pnDays);
int  PubIsLeapYear(int nYear);

void PubGetLibVer(char *pszVer);
int  PubGetErrCode(void);
void PubInitPubLib(void);
int PubGetCPLDInfo(char* pszCpldVer);
int PubCalcCRC(char *ccInput, int ccLen, char *ccOut);

unsigned char PubAmtToDispOrPnt(const char *pszInAmt, char *pszOutAmt);
int PubSetPosDateTime(const char *pszDate, const char *pszDateFormat, const char *pszTime);
void PubMoveCursor(const int nLineno, const  int nClumno);

int PubSaveVar (const char *psSaveBuf, const int nStart, const int nLen);
int PubGetVar(char * psBuf, const int nStart, const int nLen);
int ReadwatchAndEcho(void);



int PubInputIp(const char * pszTitle, const char * pszContent, char * pszOut, int * pnOutLen);
int PubSelectYesOrNo(char *pszMainMenu, char *pszTitle, char *pszStr, char *pcSelect);
unsigned char CheckXOR(unsigned char const s[],unsigned short const num);

unsigned int crc16(unsigned char *puchMsg,unsigned int usDataLen);

void PubAscToTenBcd(unsigned char *ascbuf,unsigned char *bcdbuf,int len);

void Des( unsigned char MsgIn[], unsigned char MsgOut[], unsigned char Key[], unsigned char Mode);
void CurCalc_3DES_Encrypt( unsigned char *inkey, unsigned char *indata, unsigned char *outdata );
void PBOC_DES_MAC( unsigned char *initdata,unsigned char *inputbuf, int buf_size, unsigned char *key, unsigned char *mac_buf);
void PBOC_3DES_MAC( unsigned char *initdata,unsigned char *inputbuf, int buf_size, unsigned char *key, unsigned char *mac_buf );
unsigned int crc16(unsigned char *puchMsg,unsigned int usDataLen);
QByteArray  intToByte(int number);
#endif
