/************************************************************************/
/* �ļ����ƣ�BlockInfoItem.h
/* ����ʱ�䣺2013-01-08 09:28
/*
/* ��    �������ڹ����������
/************************************************************************/
#ifndef	BLOCK_INFO_ITEM_H
#define BLOCK_INFO_ITEM_H
#include <QtCore>
#include "StockInfoItem.h"
#include "rsd_global.h"

class RSDSHARED_EXPORT CBlockInfoItem : public CAbstractStockItem
{
	Q_OBJECT
public:
	CBlockInfoItem(const QString& _file,CBlockInfoItem* parent=0);						//���캯����ֻ�������ƣ�Ȼ��ͨ������ȥ��ȡ�ļ��е��б�
	~CBlockInfoItem(void);

protected:
	//��ʼ���ӽڵ�
	void initBlock();

public:
	//����ֱ�����
	virtual QList<qRcvFenBiData*> getFenBiList();

	//������������
	void appendHistorys(const QList<qRcvHistoryData*>& list);

public:
	QString getBlockName() const{ return blockName; }			//��ȡ�������
	QString getAbsPath();										//��ȡ���ľ���·��
	QList<CAbstractStockItem*> getAbsStockList();				//��ȡȫ���б�
	QList<CStockInfoItem*> getStockList();						//��ȡ��Ʊ�б�
	QList<CBlockInfoItem*> getBlockList();						//��ȡ����б�

	bool hasBlocks();											//���ظð���Ƿ����Ӱ��

	bool appendStocks(QList<CStockInfoItem*> list);		//���������ӹ�Ʊ
	bool removeStocks(QList<CStockInfoItem*> list);		//�Ӱ����ɾ����Ʊ

	CBlockInfoItem* querySubBlock(const QStringList& _parent);	//�����Ӱ��
	bool isChildOf(CBlockInfoItem* parent);

	CBlockInfoItem* parentBlock(){ return m_pParent;}

public:
	/*�������ֶΣ�ֻ��*/
	QString getName() const;		//��Ʊ����
	float getIncrease() const;		//�Ƿ�
	float getVolumeRatio() const;	//����
	float getTurnRatio() const;		//������
	float getLastClose() const;		//��һ�����̼�
	float getOpenPrice() const;		//���տ��̼�
	float getHighPrice() const;		//������߼�
	float getLowPrice() const;		//������ͼ�
	float getNewPrice() const;		//���¼�
	float getTotalVolume() const;	//��ȡ����
	float getTotalAmount() const;	//��ȡ����
	float getNowVolume() const;		//��ȡ����
	float getIncSpeed() const;		//����
	float getPriceFluctuate() const;//�ǵ����۸񲨶�
	float getAmplitude() const;		//���
	float getAvePrice() const;		//����
	float getPERatio() const;		//��ӯ��
	float getLTSZ() const;			//��ͨ��ֵ
	float getZGB() const;			//�ܹɱ�
	float getSellVOL() const;		//������
	float getBuyVOL() const;		//������
	float getBIDVOL() const;		//ί����
	float getASKVOL() const;		//ί����
	float getCommRatio() const;		//ί��
	float getCommSent() const;		//ί��

	float getLast5Volume();			//��ȡ��ȥ5�յĳɽ��������ڼ������ȣ�

	float getMgjzc();				//ÿ�ɾ��ʲ�
	float getMgsy();				//��ȡÿ������


	/*�жϹؼ���_key�Ƿ�ƥ��*/
	bool isMatch(const QString& _key);
private:
	bool appendStocks(QList<QString> list);				//���������ӹ�Ʊ
	bool removeStocks(QList<QString> list);				//�Ӱ����ɾ����Ʊ
	bool appendBlock(CBlockInfoItem* pBlock);			//���Ӱ��


protected slots:
	void stockFenbiChanged(const QString& _code);	//ĳֻ��Ʊ�ķֱ����ݷ����ı�
	void stockHistoryChanged(const QString& _code);	//ĳֻ��Ʊ����ʷ���ݷ����ı�
	void updateData();								//��������

private:
	void addStock(CStockInfoItem* p);				//���ӹ�Ʊ
	void removeStock(CStockInfoItem* p);			//ɾ����Ʊ
	void clearTmpData();							//������ʱ�ڴ档

private:
	QString blockName;							//�������
	QString blockFilePath;						//������ݵĴ洢·��
	QList<CStockInfoItem*> stocksInBlock;		//�ð���µĹ�Ʊ��Ϣ
	QMap<QString,CBlockInfoItem*> blocksInBlock;//�ð���µ��Ӱ��

	QTimer timerUpdate;
	bool bUpdateMin;
	bool bUpdateDay;


	CBlockInfoItem* m_pParent;


	qRcvFenBiData* m_pCurFenBi;		//��ǰ�ķֱ�����

	QMap<CStockInfoItem*,float> mapLast5Price;	//���µ�5���Ӽ۸�
private:
	float fLastClose;				//�������̼�
	float fOpenPrice;				//���տ��̼�
	float fNewPrice;				//���¼�
	float fLowPrice;				//��ͼ�
	float fHighPrice;				//��߼�
	float fVolume;					//�ɽ���
	float fAmount;					//�ɽ���

	float fIncrease;				//�Ƿ�

	float fLTSZ;					//��ͨ��ֵ
	float fLTG;						//����ͨ��

	QList<QList<QChar>> shortName;	//��ƴ��
};

#endif	//BLOCK_INFO_ITEM_H