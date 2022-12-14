# ble_scan_connect.py:
from bluepy.btle import Peripheral, UUID, AssignedNumbers
from bluepy.btle import Scanner, DefaultDelegate
import time


class ScanDelegate(DefaultDelegate):
    def __init__(self):
        DefaultDelegate.__init__(self)

    def handleDiscovery(self, dev, isNewDev, isNewData):
        if isNewDev:
            print ("Discovered device", dev.addr)
        elif isNewData:
            print ("Received new data from", dev.addr)

scanner = Scanner().withDelegate(ScanDelegate())
devices = scanner.scan(10.0)
n=0
addr = []

for dev in devices:
    print ("%d: Device %s (%s), RSSI=%d dB" % (n, dev.addr, dev.addrType, dev.rssi))
    addr.append(dev.addr)
    n += 1
    for (adtype, desc, value) in dev.getScanData():
        print (" %s = %s" % (desc, value))

number = input('Enter your device number: ')
print ('Device', number)
num = int(number)
print (addr[num])
#
print ("Connecting...")
dev = Peripheral(addr[num], 'random')
#
print ("Services...")
for svc in dev.services:
    print (str(svc))




#
try:

    print('\n')
    testService = dev.getServiceByUUID(UUID(0xa000))

    # UUIDs of Characteristics in testService
    uuidlist = {0xa001, 0xa002, 0xa003}
    axis = {'x', 'y', 'z'}
    # x, y, z measurements

    while(1):
        counter = 0

        for ch in testService.getCharacteristics():
            print ("> Characteristic: ", str(ch))
            print ("-axis measurement = ")
            print ("      Read it:        ", )
            print(int.from_bytes(ch.read(),"little",signed=True))
        
        time.sleep(1)


#
finally:
    dev.disconnect()
