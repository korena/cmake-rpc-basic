/*
 * rprintmsg.c: remote version
 * of "printmsg.c"
 */
#include <stdio.h>
#include <stdlib.h>

#include "msg.h"            /* msg.h generated by rpcgen */
#include "rprintmsg.h"

int rprintmsg_1(char *server, char *message)
{
    CLIENT *clnt;
    int *result;

/*
 * Create client "handle" used for
 * calling MESSAGEPROG on the server
 * designated on the command line.
 */
    clnt = clnt_create(server, MESSAGEPROG, PRINTMESSAGEVERS, "tcp");
    if (clnt == (CLIENT *) NULL) {
/*
 * Couldn't establish connection
 * with server.
 * Print error message and die.
 */
        clnt_pcreateerror(server);
        return 1;
    }
/*
* Call the remote procedure
* "printmessage" on the server
*/
    result = printmessage_1(&message, clnt);
    if (result == (int *) NULL) {
/*
 * An error occurred while calling
* the server.
 * Print error message and die.
 */
        clnt_perror(clnt, server);
        return 1;
    }
/* Okay, we successfully called
* the remote procedure.
*/
    if (*result == 0) {
/*
 * Server was unable to print
* our message.
 * Print error message and die.
 */
        fprintf(stderr, "%s: could not print your message\n", message);
        return 1;
    }
/* The message got printed on the
* server's console
*/
    printf("Message delivered to %s\n", server);
    clnt_destroy(clnt);
    return 0;
}