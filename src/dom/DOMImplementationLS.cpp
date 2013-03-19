/*
 * DOMImplementationLS.cpp
 *
 *  Created on: 2013/02/20
 *      Author: mugwort_rc
 */

#include "DOMImplementationLS.h"

#include <boost/python.hpp>

//! for forward declaration
#include <xercesc/dom/DOMLSInput.hpp>
#include <xercesc/dom/DOMLSOutput.hpp>
#include <xercesc/dom/DOMLSSerializer.hpp>
#include <xercesc/dom/DOMLSParser.hpp>
#include <xercesc/framework/XMLGrammarPool.hpp>

#include <xercesc/dom/DOMImplementationLS.hpp>

#include "../util/XMLString.h"

namespace pyxerces {

template <class STR>
class DOMImplementationLSDefVisitor
: public boost::python::def_visitor<DOMImplementationLSDefVisitor<STR> >
{
friend class def_visitor_access;
public:
template <class T>
void visit(T& class_) const {
	class_
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const STR&, xercesc::MemoryManager* const, xercesc::XMLGrammarPool* const)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const STR&, xercesc::MemoryManager* const)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	.def("createLSParser", static_cast<xercesc::DOMLSParser*(*)(xercesc::DOMImplementationLS&, xercesc::DOMImplementationLS::DOMImplementationLSMode, const STR&)>(&DOMImplementationLSDefVisitor::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
	;
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const STR& schemaType, xercesc::MemoryManager* const manager, xercesc::XMLGrammarPool* const gramPool) {
	XMLString buff(schemaType);
	return self.createLSParser(mode, buff.ptr(), manager, gramPool);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const STR& schemaType, xercesc::MemoryManager* const manager) {
	XMLString buff(schemaType);
	return self.createLSParser(mode, buff.ptr(), manager, nullptr);
}

static xercesc::DOMLSParser* createLSParser(xercesc::DOMImplementationLS& self, xercesc::DOMImplementationLS::DOMImplementationLSMode mode, const STR& schemaType) {
	XMLString buff(schemaType);
	return self.createLSParser(mode, buff.ptr(), xercesc::XMLPlatformUtils::fgMemoryManager);
}

};

class DOMImplementationLSWrapper
: public xercesc::DOMImplementationLS, public boost::python::wrapper<xercesc::DOMImplementationLS>
{
public:
xercesc::DOMLSParser* createLSParser(const DOMImplementationLSMode mode, const XMLCh* const schemaType, xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager, xercesc::XMLGrammarPool*  const gramPool = 0) {
	return this->get_override("createLSParser")(mode, XMLString(schemaType), boost::python::ptr(manager), boost::python::ptr(gramPool));
}

xercesc::DOMLSSerializer* createLSSerializer(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createLSSerializer")(boost::python::ptr(manager));
}

xercesc::DOMLSInput* createLSInput(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createLSInput")(boost::python::ptr(manager));
}

xercesc::DOMLSOutput* createLSOutput(xercesc::MemoryManager* const manager = xercesc::XMLPlatformUtils::fgMemoryManager) {
	return this->get_override("createLSOutput")(boost::python::ptr(manager));
}

};

//! DOMImplementationLS
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSParserOverloads, createLSParser, 2, 4)
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSSerializerOverloads, createLSSerializer, 0, 1)
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSInputOverloads, createLSInput, 0, 1)
//BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(DOMImplementationLSCreateLSOutputOverloads, createLSOutput, 0, 1)

void DOMImplementationLS_init(void) {
	//! xercesc::DOMImplementationLS
	auto DOMImplementationLS = boost::python::class_<DOMImplementationLSWrapper, boost::noncopyable>("DOMImplementationLS")
			.def(DOMImplementationLSDefVisitor<XMLString>())
			.def(DOMImplementationLSDefVisitor<std::string>())
			// TODO: overloads
			.def("createLSParser", boost::python::pure_virtual(&xercesc::DOMImplementationLS::createLSParser), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createLSSerializer", boost::python::pure_virtual(&xercesc::DOMImplementationLS::createLSSerializer), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createLSInput", boost::python::pure_virtual(&xercesc::DOMImplementationLS::createLSInput), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("createLSOutput", boost::python::pure_virtual(&xercesc::DOMImplementationLS::createLSOutput), boost::python::return_value_policy<boost::python::reference_existing_object>())
			;
	boost::python::scope DOMImplementationLSScope = DOMImplementationLS;
	//! xercesc::DOMImplementationLS::DOMImplementationLSMode
	boost::python::enum_<xercesc::DOMImplementationLS::DOMImplementationLSMode>("DOMImplementationLSMode")
			.value("MODE_SYNCHRONOUS", xercesc::DOMImplementationLS::MODE_SYNCHRONOUS)
			.value("MODE_ASYNCHRONOUS", xercesc::DOMImplementationLS::MODE_ASYNCHRONOUS)
			.export_values()
			;
}

} /* namespace pyxerces */
