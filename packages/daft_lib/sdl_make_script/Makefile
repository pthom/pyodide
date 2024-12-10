# export SDL_DIR=/home/pascal/dvp/_Bundle/_Pyodide/pyodide/emsdk/emsdk/upstream/emscripten/cache/ports/sdl2/SDL-release-2.28.4/

# Compiler and Archiver
EMCC = emcc
EMAR = emar


# Source directory (set this to the SDL directory)
SRC_DIR = $(SDL_DIR)/src

# Build directory for .o files
BUILD_DIR = build

# Flags
CFLAGS = -g -sSTRICT -Werror -sRELOCATABLE -fPIC -DEMSCRIPTEN_DYNAMIC_LINKING -O2 -sUSE_SDL=0 -I$(SDL_DIR)/include
# ARFLAGS = rcs
ARFLAGS = cr


# Source files
SRC = \
  $(SRC_DIR)/SDL.c \
  $(SRC_DIR)/SDL_assert.c \
  $(SRC_DIR)/SDL_dataqueue.c \
  $(SRC_DIR)/SDL_error.c \
  $(SRC_DIR)/SDL_guid.c \
  $(SRC_DIR)/SDL_hints.c \
  $(SRC_DIR)/SDL_list.c \
  $(SRC_DIR)/SDL_log.c \
  $(SRC_DIR)/SDL_utils.c \
  $(SRC_DIR)/atomic/SDL_atomic.c \
  $(SRC_DIR)/atomic/SDL_spinlock.c \
  $(SRC_DIR)/audio/SDL_audio.c \
  $(SRC_DIR)/audio/SDL_audiocvt.c \
  $(SRC_DIR)/audio/SDL_audiodev.c \
  $(SRC_DIR)/audio/SDL_audiotypecvt.c \
  $(SRC_DIR)/audio/SDL_mixer.c \
  $(SRC_DIR)/audio/SDL_wave.c \
  $(SRC_DIR)/cpuinfo/SDL_cpuinfo.c \
  $(SRC_DIR)/dynapi/SDL_dynapi.c \
  $(SRC_DIR)/events/SDL_clipboardevents.c \
  $(SRC_DIR)/events/SDL_displayevents.c \
  $(SRC_DIR)/events/SDL_dropevents.c \
  $(SRC_DIR)/events/SDL_events.c \
  $(SRC_DIR)/events/SDL_gesture.c \
  $(SRC_DIR)/events/SDL_keyboard.c \
  $(SRC_DIR)/events/SDL_keysym_to_scancode.c \
  $(SRC_DIR)/events/SDL_scancode_tables.c \
  $(SRC_DIR)/events/SDL_mouse.c \
  $(SRC_DIR)/events/SDL_quit.c \
  $(SRC_DIR)/events/SDL_touch.c \
  $(SRC_DIR)/events/SDL_windowevents.c \
  $(SRC_DIR)/file/SDL_rwops.c \
  $(SRC_DIR)/haptic/SDL_haptic.c \
  $(SRC_DIR)/joystick/controller_type.c \
  $(SRC_DIR)/joystick/SDL_gamecontroller.c \
  $(SRC_DIR)/joystick/SDL_joystick.c \
  $(SRC_DIR)/power/SDL_power.c \
  $(SRC_DIR)/render/SDL_d3dmath.c \
  $(SRC_DIR)/render/SDL_render.c \
  $(SRC_DIR)/render/SDL_yuv_sw.c \
  $(SRC_DIR)/render/direct3d/SDL_render_d3d.c \
  $(SRC_DIR)/render/direct3d11/SDL_render_d3d11.c \
  $(SRC_DIR)/render/opengl/SDL_render_gl.c \
  $(SRC_DIR)/render/opengl/SDL_shaders_gl.c \
  $(SRC_DIR)/render/opengles/SDL_render_gles.c \
  $(SRC_DIR)/render/opengles2/SDL_render_gles2.c \
  $(SRC_DIR)/render/opengles2/SDL_shaders_gles2.c \
  $(SRC_DIR)/render/psp/SDL_render_psp.c \
  $(SRC_DIR)/render/software/SDL_blendfillrect.c \
  $(SRC_DIR)/render/software/SDL_blendline.c \
  $(SRC_DIR)/render/software/SDL_blendpoint.c \
  $(SRC_DIR)/render/software/SDL_drawline.c \
  $(SRC_DIR)/render/software/SDL_drawpoint.c \
  $(SRC_DIR)/render/software/SDL_render_sw.c \
  $(SRC_DIR)/render/software/SDL_rotate.c \
  $(SRC_DIR)/render/software/SDL_triangle.c \
  $(SRC_DIR)/sensor/SDL_sensor.c \
  $(SRC_DIR)/sensor/dummy/SDL_dummysensor.c \
  $(SRC_DIR)/stdlib/SDL_crc16.c \
  $(SRC_DIR)/stdlib/SDL_crc32.c \
  $(SRC_DIR)/stdlib/SDL_getenv.c \
  $(SRC_DIR)/stdlib/SDL_iconv.c \
  $(SRC_DIR)/stdlib/SDL_malloc.c \
  $(SRC_DIR)/stdlib/SDL_qsort.c \
  $(SRC_DIR)/stdlib/SDL_stdlib.c \
  $(SRC_DIR)/stdlib/SDL_string.c \
  $(SRC_DIR)/stdlib/SDL_strtokr.c \
  $(SRC_DIR)/thread/SDL_thread.c \
  $(SRC_DIR)/timer/SDL_timer.c \
  $(SRC_DIR)/video/SDL_RLEaccel.c \
  $(SRC_DIR)/video/SDL_blit.c \
  $(SRC_DIR)/video/SDL_blit_0.c \
  $(SRC_DIR)/video/SDL_blit_1.c \
  $(SRC_DIR)/video/SDL_blit_A.c \
  $(SRC_DIR)/video/SDL_blit_N.c \
  $(SRC_DIR)/video/SDL_blit_auto.c \
  $(SRC_DIR)/video/SDL_blit_copy.c \
  $(SRC_DIR)/video/SDL_blit_slow.c \
  $(SRC_DIR)/video/SDL_bmp.c \
  $(SRC_DIR)/video/SDL_clipboard.c \
  $(SRC_DIR)/video/SDL_egl.c \
  $(SRC_DIR)/video/SDL_fillrect.c \
  $(SRC_DIR)/video/SDL_pixels.c \
  $(SRC_DIR)/video/SDL_rect.c \
  $(SRC_DIR)/video/SDL_shape.c \
  $(SRC_DIR)/video/SDL_stretch.c \
  $(SRC_DIR)/video/SDL_surface.c \
  $(SRC_DIR)/video/SDL_video.c \
  $(SRC_DIR)/video/SDL_yuv.c \
  $(SRC_DIR)/video/emscripten/SDL_emscriptenevents.c \
  $(SRC_DIR)/video/emscripten/SDL_emscriptenframebuffer.c \
  $(SRC_DIR)/video/emscripten/SDL_emscriptenmouse.c \
  $(SRC_DIR)/video/emscripten/SDL_emscriptenopengles.c \
  $(SRC_DIR)/video/emscripten/SDL_emscriptenvideo.c \
  $(SRC_DIR)/audio/emscripten/SDL_emscriptenaudio.c \
  $(SRC_DIR)/video/dummy/SDL_nullevents.c \
  $(SRC_DIR)/video/dummy/SDL_nullframebuffer.c \
  $(SRC_DIR)/video/dummy/SDL_nullvideo.c \
  $(SRC_DIR)/video/yuv2rgb/yuv_rgb.c \
  $(SRC_DIR)/audio/disk/SDL_diskaudio.c \
  $(SRC_DIR)/audio/dummy/SDL_dummyaudio.c \
  $(SRC_DIR)/loadso/dlopen/SDL_sysloadso.c \
  $(SRC_DIR)/power/emscripten/SDL_syspower.c \
  $(SRC_DIR)/joystick/emscripten/SDL_sysjoystick.c \
  $(SRC_DIR)/filesystem/emscripten/SDL_sysfilesystem.c \
  $(SRC_DIR)/timer/unix/SDL_systimer.c \
  $(SRC_DIR)/haptic/dummy/SDL_syshaptic.c \
  $(SRC_DIR)/main/dummy/SDL_dummy_main.c \
  $(SRC_DIR)/locale/SDL_locale.c \
  $(SRC_DIR)/locale/emscripten/SDL_syslocale.c \
  $(SRC_DIR)/misc/SDL_url.c \
  $(SRC_DIR)/misc/emscripten/SDL_sysurl.c \
  $(SRC_DIR)/thread/generic/SDL_syscond.c \
  $(SRC_DIR)/thread/generic/SDL_sysmutex.c \
  $(SRC_DIR)/thread/generic/SDL_syssem.c \
  $(SRC_DIR)/thread/generic/SDL_systhread.c \
  $(SRC_DIR)/thread/generic/SDL_systls.c

# Object files
OBJ = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))

# Output library
LIB = libSDL2.a

# Default target
all: $(LIB)

# Rule to create the library
$(LIB): $(OBJ)
	$(EMAR) $(ARFLAGS) $@ $^

# Rule to compile .c files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)  # Create the necessary subdirectories in build/
	$(EMCC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated files
clean:
	rm -rf $(BUILD_DIR) $(LIB)
