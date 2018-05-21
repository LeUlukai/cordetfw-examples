/**
 * @file
 * @ingroup crDemoSlave1
 * OutComponent encapsulating a report generated by a Slave Application when a temperature
 * violation has been detected.
 * An OutComponent is defined by defining the functions which override its
 * adaptation points, namely (see <code>CrFwOutCmp.h</code>):
 * - The Enable Check Operation
 * - The Ready Check Operation
 * - The Serialize Operation
 * .
 * These operations are defined as follows for the temperature violation report:
 * - Enable Check Operation: the default Enable Check Operation of
 *   <code>CrFwOutCmpDefEnableCheck.h</code> is used.
 * - Ready Check Operation: the default Ready Check Operation of
 *   <code>CrFwSmCheckAlwaysTrue.h</code> is used.
 * - Serialize Operation: this operation calls the default Serialize Operation of
 *   <code>CrFwOutCmpDefSerialize.h</code> and then it writes the temperature
 *   which violated the limit in the first byte of the parameter part of the report packet;
 *   and it sets the command destination to be the Master Application.
 * .
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

#ifndef CRMA_OUTCMP_TEMP_VIOLATION_H_
#define CRMA_OUTCMP_TEMP_VIOLATION_H_

/* Include framework components */
#include "CrFwConstants.h"
/* Include FW Profile components */
#include "FwSmCore.h"

/**
 * Implementation of the Serialize Operation for the report for a temperature violation.
 * This operation calls the default Serialize Operation of
 * <code>CrFwOutCmpDefSerialize.h</code> and then writes the temperature
 * which violated the limit in the first byte of the parameter part of the report packet;
 * and it sets the command destination to be the Master Application.
 * The value of the limit violating temperature is set through function
 * <code>CrDaOutCmpTempViolationSetTemp</code>.
 * @param smDesc the descriptor of the OutComponent state machine
 * @return the value of the Enable Flag
 */
void CrDaOutCmpTempViolationSerialize(FwSmDesc_t smDesc);

/**
 * Set the value of the limit violating temperature (an integer in the range 0 to 255).
 * @param temp the limit violating temperature
 */
void CrDaOutCmpTempViolationSetTemp(char temp);

#endif /* CRMA_OUTCMP_TEMP_VIOLATION_H_ */
