#ifndef URN_JAUS_JSS_CORE_DISCOVERY_1_0_REPORTIDENTIFICATION_H
#define URN_JAUS_JSS_CORE_DISCOVERY_1_0_REPORTIDENTIFICATION_H

#include "JausUtils.h"
#include "Messages/Message.h"
#include "JConstants.h"
namespace urn_jaus_jss_core_Discovery_1_0
{

class DllExport ReportIdentification: public JTS::Message
{
public:
	static const int ID = 0x4b00;
	
	class DllExport JAUSApplicationLayerHeader
	{
	public:
		class DllExport HeaderRec
		{
		public:
			void setParent(JAUSApplicationLayerHeader* parent);
			void setParentPresenceVector();
			jUnsignedShortInteger getMessageID();
			int setMessageID(jUnsignedShortInteger value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			HeaderRec &operator=(const HeaderRec &value);
			bool operator==(const HeaderRec &value) const;
			bool operator!=(const HeaderRec &value) const;
			HeaderRec();
			HeaderRec(const HeaderRec &value);
			virtual ~HeaderRec();
		
		protected:
			JAUSApplicationLayerHeader* m_parent;
			jUnsignedShortInteger m_MessageID;
		};
	
		HeaderRec* const getHeaderRec();
		int setHeaderRec(const HeaderRec &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		JAUSApplicationLayerHeader &operator=(const JAUSApplicationLayerHeader &value);
		bool operator==(const JAUSApplicationLayerHeader &value) const;
		bool operator!=(const JAUSApplicationLayerHeader &value) const;
		JAUSApplicationLayerHeader();
		JAUSApplicationLayerHeader(const JAUSApplicationLayerHeader &value);
		virtual ~JAUSApplicationLayerHeader();
	
	protected:
		HeaderRec m_HeaderRec;
	};
	class DllExport Body
	{
	public:
		class DllExport ReportIdentificationRec
		{
		public:
			void setParent(Body* parent);
			void setParentPresenceVector();
			jUnsignedByte getQueryType();
			int setQueryType(jUnsignedByte value);
			jUnsignedShortInteger getType();
			int setType(jUnsignedShortInteger value);
			jVariableLengthString getIdentification();
			int setIdentification(jVariableLengthString value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			ReportIdentificationRec &operator=(const ReportIdentificationRec &value);
			bool operator==(const ReportIdentificationRec &value) const;
			bool operator!=(const ReportIdentificationRec &value) const;
			ReportIdentificationRec();
			ReportIdentificationRec(const ReportIdentificationRec &value);
			virtual ~ReportIdentificationRec();
		
		protected:
			Body* m_parent;
			jUnsignedByte m_QueryType;
			jUnsignedShortInteger m_Type;
			jVariableLengthString m_Identification;
		};
	
		ReportIdentificationRec* const getReportIdentificationRec();
		int setReportIdentificationRec(const ReportIdentificationRec &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		Body &operator=(const Body &value);
		bool operator==(const Body &value) const;
		bool operator!=(const Body &value) const;
		Body();
		Body(const Body &value);
		virtual ~Body();
	
	protected:
		ReportIdentificationRec m_ReportIdentificationRec;
	};

	unsigned int getID() { return ID; };
	JAUSApplicationLayerHeader* const getJAUSApplicationLayerHeader();
	int setJAUSApplicationLayerHeader(const JAUSApplicationLayerHeader &value);
	Body* const getBody();
	int setBody(const Body &value);
	const unsigned int getSize();
	virtual void encode(unsigned char *bytes);
	virtual void decode(const unsigned char *bytes);
	ReportIdentification &operator=(const ReportIdentification &value);
	bool operator==(const ReportIdentification &value) const;
	bool operator!=(const ReportIdentification &value) const;
	ReportIdentification();
	ReportIdentification(const ReportIdentification &value);
	virtual ~ReportIdentification();

protected:
	JAUSApplicationLayerHeader m_JAUSApplicationLayerHeader;
	Body m_Body;
};

}

#endif // URN_JAUS_JSS_CORE_DISCOVERY_1_0_REPORTIDENTIFICATION_H
