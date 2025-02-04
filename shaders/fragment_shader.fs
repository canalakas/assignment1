#version 330 core
out vec4 FragColor;
uniform bool isDashed;

void main() {
    if (isDashed) {
        float dash = mod(gl_FragCoord.x / 20.0, 2.0);
        if (dash < 1.0) {
            FragColor = vec4(0.0, 0.0, 0.0, 1.0);
        } else {
            discard;
        }
    } else {
        FragColor = vec4(0.0, 0.0, 0.0, 1.0);
    }
}
