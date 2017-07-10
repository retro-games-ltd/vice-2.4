g++  -g -O3 -march=native -Wstrict-prototypes -Wall -Wno-inline -I/usr/local/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT   -o the64 \
alarm.o \
attach.o \
autostart.o \
autostart-prg.o \
charset.o \
clkguard.o \
clipboard.o \
cmdline.o \
cbmdos.o \
cbmimage.o \
color.o \
crc32.o \
datasette.o \
debug.o \
dma.o \
embedded.o \
event.o \
findpath.o \
fliplist.o \
gcr.o \
info.o \
init.o \
initcmdline.o \
interrupt.o \
ioutil.o \
joystick.o \
kbdbuf.o \
keyboard.o \
lib.o \
libm_math.o \
lightpen.o \
log.o \
machine-bus.o \
machine.o \
network.o \
opencbmlib.o \
palette.o \
ram.o \
rawfile.o \
rawnet.o \
resources.o \
romset.o \
screenshot.o \
snapshot.o \
socket.o \
sound.o \
sysfile.o \
translate.o \
traps.o \
util.o \
vsync.o \
zfile.o \
zipcode.o \
maincpu.o \
mouse.o \
midi.o \
../src/c64/libc64.a \
../src/c64/cart/libc64cartsystem.a \
../src/c64/cart/libc64cart.a \
../src/c64/cart/libc64commoncart.a \
../src/drive/iec/libdriveiec.a \
../src/drive/iecieee/libdriveiecieee.a \
../src/drive/iec/c64exp/libdriveiecc64exp.a \
../src/drive/ieee/libdriveieee.a \
../src/drive/libdrive.a \
../src/lib/p64/libp64.a \
../src/iecbus/libiecbus.a \
../src/parallel/libparallel.a \
../src/vdrive/libvdrive.a \
../src/sid/libsid.a \
../src/monitor/libmonitor.a \
../src/sounddrv/libsounddrv.a \
../src/gfxoutputdrv/libgfxoutputdrv.a \
../src/printerdrv/libprinterdrv.a \
../src/rs232drv/librs232drv.a \
../src/diskimage/libdiskimage.a \
../src/fsdevice/libfsdevice.a \
../src/tape/libtape.a \
../src/fileio/libfileio.a \
../src/serial/libserial.a \
../src/core/libcore.a \
../src/vicii/libvicii.a \
../src/raster/libraster.a \
../src/userport/libuserport.a \
../src/rtc/librtc.a \
../src/video/libvideo.a \
/home/chris/src/the64-hardware/firmware/src/vice/libthe64.a \
/home/chris/src/the64-hardware/firmware/src/common/libtsfcommon.a \
../src/imagecontents/libimagecontents.a \
../src/resid/libresid.a \
../src/resid-fp/libresidfp.a \
\
../src/platform/libplatform.a \
-lasound \
-ljpeg \
-lz \
-ldl \
-lnsl \
-lm \
-ldl \
-lpthread \
-L/usr/local/lib \
-Wl,-rpath,/usr/local/lib \
-lGLESv2 -lEGL -lpng -lm -lX11

exit


main.o 

-lSDL \
-lpthread \
-lSDLmain \
-lSDL

#../src/arch/sdl/libarch.a   \
