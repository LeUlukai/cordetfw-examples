/**
 * @file
 * @ingroup crDemoMaster
 * Temperature Violation InReport.
 * The Temperature Violation InReport is the Report generated by a Slave Application
 * when there has been temperature limit violation.
 * In general, an InReport is defined by defining the functions which override its
 * adaptation points, namely (see <code>CrFwInRep.h</code>):
 * - The Validity Check Operation
 * - The Update Action Operation
 * .
 * In the case of the Temperature Violation InReport, these functions are
 * defined as follows:
 * - The Validity Check always reports: "valid"
 * - The Update Action Operation writes a message to standard output describing the
 *   temperature violation.
 * .
 * This module defines functions which implement the above operations.
 * These functions are associated to a specific kind of InReport in
 * the initializer <code>#CR_FW_INREP_INIT_KIND_DESC</code>.
 *
 * @author Vaclav Cechticky <vaclav.cechticky@pnp-software.com>
 * @author Alessandro Pasetti <pasetti@pnp-software.com>
 * @copyright P&P Software GmbH, 2013, All Rights Reserved
 *
 * This file is part of the CORDET Framework.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * For information on alternative licensing, please contact P&P Software GmbH.
 */

#ifndef CRMA_INREP_TEMP_VIOL_H_
#define CRMA_INREP_TEMP_VIOL_H_

/* Include configuration files */
#include "CrFwUserConstants.h"
/* Include framework components */
#include "CrFwConstants.h"
/* Include FW Profile components */
#include "FwSmCore.h"

/**
 * Implementation of the Validity Check Operation for the Master Application.
 * This function always returns true.
 * @param prDesc the descriptor of the InReport reset procedure
 * @return always return true
 */
CrFwBool_t CrMaInRepTempViolationValidityCheck(FwPrDesc_t prDesc);

/**
 * Implementation of the Update Action Operation for the Master Application.
 * This function writes a message to <code>stdout</code> with the following
 * information:
 * - the sequence counter of the incoming report
 * - the source application for the incoming report (either Slave 1 or Slave 2)
 * - the value of the temperature which violates the limit
 * .
 * This function assumes that the temperature is stored in the first byte of
 * the parameter area of the report packet.
 * @param prDesc the descriptor of the InReport procedure
 */
void CrMaInRepTempViolationUpdateAction(FwPrDesc_t prDesc);

#endif /* CRFW_INREP_SAMPLE1_H_ */
