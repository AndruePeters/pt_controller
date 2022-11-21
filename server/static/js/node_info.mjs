'use strict'

class WifiInfo {
    constructor() {
        this.rssid = -100; 
    }
}

class NodeInfo {
    mac = "";
    name = "";
    constructor(mac, name) {
        this.name = name;
        this.mac = mac;
    }
}

export {NodeInfo};