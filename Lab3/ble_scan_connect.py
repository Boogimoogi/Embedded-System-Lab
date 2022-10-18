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
    testService = dev.getServiceByUUID(UUID(0xfff0))

    # UUIDs of Characteristics in testService
    uuidlist = {0xfff1, 0xfff2, 0xfff3, 0xfff4}


    for ch in testService.getCharacteristics():
        print ("> Characteristic: ", str(ch))
        print ("    Supports Read?: ", ch.supportsRead())
        if(ch.supportsRead()):
            print ("      Read it:        ", ch.read().decode('utf-8'))
        
        CCCD = ch.getDescriptors(forUUID=AssignedNumbers.clientCharacteristicConfiguration)
        if not len(CCCD) == 0:
            CCCD = CCCD[0]
            print("    CCCD:            ", str(CCCD))
            print("      Read it:         ", CCCD.read().hex())

            CCCD.write(b"\x01\x01")
            print("      Write x01x01 :", time.strftime("%H:%M:%S", time.localtime()))
            print("      Read it again:   ", CCCD.read().hex())
            








    print('\nGet Characteristics Directly')
    for j in uuidlist:
        ch = dev.getCharacteristics(uuid=UUID(j))[0]
        print ("> Characteristic: ", str(ch))
        print ("    Supports Read?: ", ch.supportsRead())
        if(ch.supportsRead()):
            print ("      Read it:        ", ch.read().decode('utf-8'))
        
        CCCD = ch.getDescriptors(forUUID=AssignedNumbers.clientCharacteristicConfiguration)
        if not len(CCCD) == 0:
            CCCD = CCCD[0]
            print("    CCCD:            ", str(CCCD))
            print("      Read it:         ", CCCD.read().hex())

            CCCD.write(b"\x01\x01")
            print("      Write x01x01 :", time.strftime("%H:%M:%S", time.localtime()))
            print("      Read it again:   ", CCCD.read().hex())
#
finally:
    dev.disconnect()
