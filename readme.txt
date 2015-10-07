
This extension is based on UIMA 2.4.0 rc7

(1) Rendering of UimaString is not supported out of the box in gdb. Hence, it is important to add generators
for uima strings. You need to copy & paste the following functions into printers.py:

========== code start ==========
# http://stackoverflow.com/questions/17456001/examining-memory-in-gdb-pretty-printer
class UnicodeStringPrinter:
    def __init__(self, typename, val):
        self.val = val

    def to_string(self):
        ptr_int32t_type = gdb.lookup_type("int32_t").pointer()
        ptr_length = self.val['fLength'].address.cast(ptr_int32t_type)
        ptr_ucharptr_type = gdb.lookup_type("UChar").pointer()
        ptr_uchar = self.val['fArray'].dereference().address.cast(ptr_ucharptr_type)
        res = '"'
        for x in range(0, int(ptr_length.dereference())):
            res += unichr(int(ptr_uchar.dereference()))
            ptr_uchar += 1
        res += '"'

        return res;

    def display_hint(self):
        return 'UnicodeString'
=========== code end ==========

The file printers.py is located in your gdb installation. If you use CLion, an example path is:
~/clion-1.0.5/bin/gdb/share/gdb/stl_printers/libstdcxx/v6/printers.py. Should you open your files
with PyCharm, the project directory would be ~/clion-1.0.5/bin/gdb/share/gdb

(2) Add the handler line into printers.py -> build_libstdcxx_dictionary():

For testing purposes, you can adjust and launch the configuration component.exe in CLion.