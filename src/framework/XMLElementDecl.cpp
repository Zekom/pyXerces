/*
 * XMLElementDecl.cpp
 *
 *  Created on: 2013/02/23
 *      Author: mugwort_rc
 */

#include "XMLElementDecl.h"

#include <boost/python.hpp>
#include <xercesc/validators/common/ContentSpecNode.hpp>	//!< for forward declaration
#include <xercesc/framework/XMLContentModel.hpp>			//!< for forward declaration
#include <xercesc/framework/XMLElementDecl.hpp>

namespace pyxerces {

void XMLElementDecl_init(void) {
	//! xercesc::XMLElementDecl
	auto XMLElementDecl = boost::python::class_<xercesc::XMLElementDecl, boost::noncopyable, boost::python::bases<xercesc::XSerializable> >("XMLElementDecl", boost::python::no_init)
			.def("getAttDefList", &xercesc::XMLElementDecl::getAttDefList, boost::python::return_internal_reference<>())
			.def("getCharDataOpts", &xercesc::XMLElementDecl::getCharDataOpts)
			.def("hasAttDefs", &xercesc::XMLElementDecl::hasAttDefs)
			.def("getContentSpec", static_cast<xercesc::ContentSpecNode*(xercesc::XMLElementDecl::*)(void)>(&xercesc::XMLElementDecl::getContentSpec), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContentSpec", &xercesc::XMLElementDecl::setContentSpec)
			.def("getContentModel", &xercesc::XMLElementDecl::getContentModel, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("setContentModel", &xercesc::XMLElementDecl::setContentModel)
			.def("getFormattedContentModel", &xercesc::XMLElementDecl::getFormattedContentModel, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getBaseName", static_cast<const XMLCh*(xercesc::XMLElementDecl::*)(void) const>(&xercesc::XMLElementDecl::getBaseName), boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getURI", &xercesc::XMLElementDecl::getURI)
			.def("getElementName", static_cast<xercesc::QName*(xercesc::XMLElementDecl::*)(void)>(&xercesc::XMLElementDecl::getElementName), boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def("getFullName", &xercesc::XMLElementDecl::getFullName, boost::python::return_value_policy<boost::python::return_by_value>())
			.def("getId", &xercesc::XMLElementDecl::getId)
			.def("isDeclared", &xercesc::XMLElementDecl::isDeclared)
			.def("isExternal", &xercesc::XMLElementDecl::isExternal)
			.def("getMemoryManager", &xercesc::XMLElementDecl::getMemoryManager, boost::python::return_value_policy<boost::python::reference_existing_object>())
			.def_readonly("fgInvalidElemId", &xercesc::XMLElementDecl::fgInvalidElemId)
			.def_readonly("fgPCDataElemId", &xercesc::XMLElementDecl::fgPCDataElemId)
			.def_readonly("fgPCDataElemName", &xercesc::XMLElementDecl::fgPCDataElemName)
			;
	boost::python::scope XMLElementDeclScope = XMLElementDecl;
	//! xercesc::XMLElementDecl::CreateReasons
	boost::python::enum_<xercesc::XMLElementDecl::CreateReasons>("CreateReasons")
			.value("NoReason", xercesc::XMLElementDecl::NoReason)
			.value("Declared", xercesc::XMLElementDecl::Declared)
			.value("AttList", xercesc::XMLElementDecl::AttList)
			.value("InContentModel", xercesc::XMLElementDecl::InContentModel)
			.value("AsRootElem", xercesc::XMLElementDecl::AsRootElem)
			.value("JustFaultIn", xercesc::XMLElementDecl::JustFaultIn)
			.export_values()
			;
	//! xercesc::XMLElementDecl::CharDataOpts
	boost::python::enum_<xercesc::XMLElementDecl::CharDataOpts>("CharDataOpts")
			.value("NoCharData", xercesc::XMLElementDecl::NoCharData)
			.value("SpacesOk", xercesc::XMLElementDecl::SpacesOk)
			.value("AllCharData", xercesc::XMLElementDecl::AllCharData)
			.export_values()
			;
}

} /* namespace pyxerces */
