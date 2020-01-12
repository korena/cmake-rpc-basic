Based on [rpcgen Developer's guide](https://docs.oracle.com/cd/E19683-01/816-1435/rpcgenpguide-21470/index.html)

- prerequisites

    - remote:
        1. rpcbind

    - local:
        1. rpcbind
        2. libnss3
        3. libnss-db

- usage:
    1. Copy resulting rpc_server to the remote machine
    2. run `sudo ./rpc_server` on the remote machine
    3. run `sudo ./rpc_local_bin <remote-machine-name-or-ip> "message to print remotely"`
