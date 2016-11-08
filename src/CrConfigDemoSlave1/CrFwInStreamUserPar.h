/**
 * @file
 * @ingroup crConfigDemoSlave1
 * User-modifiable parameters for the InStream components (see <code>CrFwInStream.h</code>)
 * of the Slave 1 Application of the CORDET Demo.
 *
 * The parameters defined in this file determine the configuration of the InStream Components.
 * The value of these parameters cannot be changed dynamically.
 * CORDET Framework.
 *
 * The Slave 1 Application receives packets from the Master Application and from the Slave 2
 * application for re-routing to the Master Application.
 * It therefore needs two InStream instances.
 * The physical connection to the Master Application and to the Slave 2 Application is through
 * a server socket.
 * The interface to the server socket is encapsulated in <code>CrMaServerSocket.h</code>.
 *
 * @author Vaclav Cechticky <vaclav.cechticky@pnp-software.com>
 * @author Alessandro Pasetti <pasetti@pnp-software.com>
 * @copyright P&P Software GmbH, 2013, All Rights Reserved
 * @version GPLv3_0.7.1
 *
 * This file is part of CORDET Framework.
 *
 * CORDET Framework is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * CORDET Framework is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with CORDET Framework.  If not, see <http://www.gnu.org/licenses/>.
 *
 * For information on alternative licensing, please contact P&P Software GmbH.
 */

#ifndef CR_FW_INSTREAM_USERPAR_H_
#define CR_FW_INSTREAM_USERPAR_H_

/* Include framework files */
#include "InStream/CrFwInStream.h"
#include "BaseCmp/CrFwResetProc.h"
/* Include Demo Application files */
#include "CrDaServerSocket.h"
#include "CrDaConstants.h"

/**
 * The number of InStream components in the application.
 * The value of this constant must be smaller than the range of the <code>::CrFwCounterU1_t</code>
 * integer type.
 */
#define CR_FW_NOF_INSTREAM 2

/**
 * The sizes of the packet queues in the InStream components.
 * Each InStream has one packet queue.
 * This constant defines the size of the packet queue of the i-th InStream.
 * The size of the packet queue represents the maximum number of packets which
 * may remain pending in the packet queue.
 * The size of a packet queue must be a positive integer (i.e. it is not legal
 * to define a zero-size packet queue).
 */
#define CR_FW_INSTREAM_PQSIZE {10,10}

/**
 * The packet sources which are managed by the InStream components.
 * Each InStream is responsible for collecting packets from one packet source.
 * This constant is the initializer for the array which defines the packet source
 * associated to the i-th InStream.
 */
#define CR_FW_INSTREAM_SRC {CR_DA_MASTER,CR_DA_SLAVE_2}

/**
 * The number of groups of the InStream components.
 * The number of groups must be a positive integer.
 * This array defines the number of groups of the i-th InStream.
 *
 * The number of groups defined in this file are those used for the Slave 1 Application.
 */
#define CR_FW_INSTREAM_NOF_GROUPS {1,1}

/**
 * The functions implementing  the Packet Collect Operations of the InStream components.
 * Each InStream component needs to be able to collect a packet from the middleware.
 * The function implementing this packet collect operation is one of the
 * adaptation points of the framework.
 * This array defines the packet collect operations for the InStreams.
 * The items in the arrays must be function pointers of type:
 * <code>::CrFwPcktCollect_t</code>.
 *
 * The packet collection operation defined in this file is the one provided
 * by the socket-based interface of <code>CrDaServerSocket.h</code>.
 */
#define CR_FW_INSTREAM_PCKTCOLLECT {&CrDaServerSocketPcktCollect, &CrDaServerSocketPcktCollect}

/**
 * The functions implementing the Packet Available Check Operations of the InStream
 * components.
 * Each InStream component needs to be able to check whether the middleware is in
 * state WAITING (no packet is available for collection) or PCKT_AVAIL (a packet is
 * available for collection).
 * The functions which query the middleware to check whether a packet is available or not
 * is one of the adaptation points of the framework.
 * This array defines the Packet Available Check Operations for the InStream.
 * The items in the array must be function pointers of type:
 * <code>::CrFwPcktAvailCheck_t</code>.
 *
 * The packet collection operation defined in this file is the one provided
 * by the socket-based interface of <code>CrDaServerSocket.h</code>.
 */
#define CR_FW_INSTREAM_PCKTAVAILCHECK {&CrDaServerSocketIsPcktAvail,  \
									   &CrDaServerSocketIsPcktAvail}

/**
 * The functions implementing the Initialization Check of the InStream components.
 * The InStream components are derived from the Base Component and they therefore
 * inherit its Initialization Procedure (see <code>CrFwInitProc.h</code>).
 * The initialization procedure must be configured with two actions:
 * the Initialization Action and the Initialization Check.
 * This constant defines the functions implementing the Initialization Checks
 * for the the InStream components.
 * The items in the array must be function pointers of type:
 * <code>FwPrAction_t</code>.
 *
 * Function <code>::CrFwBaseCmpDefInitCheck</code> can be used as a default
 * implementation for this function.
 *
 * The initialization check operation defined in this file is the one provided
 * by the socket-based interface of <code>CrDaServerSocket.h</code>.
 */
#define CR_FW_INSTREAM_INITCHECK {&CrDaServerSocketInitCheck, \
	                              &CrDaServerSocketInitCheck}

/**
 * The functions implementing the Initialization Action of the InStream components.
 * The InStream components are derived from the Base Component and they therefore
 * inherit its Initialization Procedure (see <code>CrFwInitProc.h</code>).
 * The initialization procedure must be configured with two actions:
 * the Initialization Action and the Initialization Check.
 * This constant defines the functions implementing the Initialization Actions
 * for the the InStream components.
 * The items in the array must be function pointers of type:
 * <code>FwPrAction_t</code>.
 *
 * Function <code>::CrFwInStreamDefInitAction</code> can be used as a default
 * implementation for this function.
 * This function initializes the internal data structures for the InStream.
 * An application-specific Initialization Action should therefore include a call
 * to this function.
 *
 * The initialization check operation defined in this file is the one provided
 * by the socket-based interface of <code>CrDaServerSocket.h</code>.
 */
#define CR_FW_INSTREAM_INITACTION {&CrDaServerSocketInitAction, \
	                               &CrDaServerSocketInitAction}

/**
 * The functions implementing the Configuration Check of the InStream components.
 * The InStream components are derived from the Base Component and they therefore
 * inherit its Reset Procedure (see <code>CrFwResetProc.h</code>).
 * The reset procedure must be configured with two actions:
 * the Configuration Action and the Configuration Check.
 * This constant defines the functions implementing the Configuration Checks
 * for the the InStream components.
 * The items in the array must be function pointers of type:
 * <code>FwPrAction_t</code>.
 *
 * Function <code>::CrFwBaseCmpDefConfigCheck</code> can be used as a default
 * implementation for this function.
 */
#define CR_FW_INSTREAM_CONFIGCHECK {&CrFwBaseCmpDefConfigCheck, \
	                                &CrFwBaseCmpDefConfigCheck}

/**
 * The functions implementing the Configuration Action of the InStream components.
 * The InStream components are derived from the Base Component and they therefore
 * inherit its Reset Procedure (see <code>CrFwResetProc.h</code>).
 * The reset procedure must be configured with two actions:
 * the Configuration Action and the Configuration Check.
 * This constant defines the functions implementing the Configuration Actions
 * for the the InStream components.
 * The items in the array must be function pointers of type:
 * <code>FwPrAction_t</code>.
 *
 * Function <code>::CrFwInStreamDefConfigAction</code> can be used as a default
 * implementation for this function.
 * This function initializes the internal data structures for the InStream.
 * An application-specific Configuration Action should therefore include a call
 * to this function.
 *
 * The configuration action operation defined in this file is the one provided
 * by the socket-based interface of <code>CrDaServerSocket.h</code>.
 */
#define CR_FW_INSTREAM_CONFIGACTION {&CrDaServerSocketConfigAction, \
	                                 &CrDaServerSocketConfigAction}

/**
 * The functions implementing the Shutdown Action of the InStream components.
 * The InStream components are derived from the Base Component and they therefore
 * inherit its Shutdown Action (see <code>CrFwBaseCmp.h</code>).
 * This constant defines the shutdown functions for the the InStream components.
 * The items in the array must be function pointers of type:
 * <code>FwSmAction_t</code>.
 *
 * Function <code>::CrFwInStreamDefShutdownAction</code> can be used as a default
 * implementation for this function.
 * This function initializes the internal data structures for the InStream.
 * An application-specific Shutdown Action should therefore include a call
 * to this function.
 *
 * The shutdown action operation defined in this file is the one provided
 * by the socket-based interface of <code>CrDaServerSocket.h</code>.
 */
#define CR_FW_INSTREAM_SHUTDOWNACTION {&CrDaServerSocketShutdownAction, \
									   &CrDaServerSocketShutdownAction}

#endif /* CR_FW_INSTREAM_USERPAR_H_ */
