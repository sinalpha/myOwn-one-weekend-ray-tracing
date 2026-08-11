"""Convert a PPM image (P3/P6) to PNG using Pillow."""
import sys
from pathlib import Path

from PIL import Image


def convert(ppm_path: str, png_path: str | None = None) -> Path:
    src = Path(ppm_path)
    dst = Path(png_path) if png_path else src.with_suffix(".png")
    with Image.open(src) as img:
        img.save(dst)
    return dst


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python ppm_to_png.py <input.ppm> [output.png]")
        sys.exit(1)

    output = convert(sys.argv[1], sys.argv[2] if len(sys.argv) > 2 else None)
    print(f"Wrote {output}")
