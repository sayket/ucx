/**
* Copyright (C) Mellanox Technologies Ltd. 2001-2018.  ALL RIGHTS RESERVED.
*
* See file LICENSE for terms.
*/


#ifndef UCP_LISTENER_H_
#define UCP_LISTENER_H_

#include "ucp_worker.h"
#include "wireup/wireup_ep.h"


/**
 * UCP listener
 */
typedef struct ucp_listener {
    ucp_worker_iface_t              wiface;  /* UCT iface to listen on */
    ucp_listener_accept_callback_t  cb;      /* Listen accept callback */
    void                            *arg;    /* User's arg for the accept callback */
    uct_worker_cb_id_t              prog_id; /* Slow-path callback */
} ucp_listener_t;


/**
 * Accepted connection on a listener
 */
typedef struct ucp_listener_accept {
    ucp_listener_h          listener;       /* Listener on which the
                                               connection was accepted */
    void                    *wireup_data;   /* Wireup private data*/
} ucp_listener_accept_t;

void ucp_listener_schedule_accept_cb(ucp_ep_h ep);

int ucp_listener_accept_cb_remove_filter(const ucs_callbackq_elem_t *elem,
                                         void *arg);

#endif
