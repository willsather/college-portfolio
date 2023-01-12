import './style.css'
import * as THREE from 'three'

// Canvas
const canvas = document.querySelector('canvas.webgl')

// Scene
const scene = new THREE.Scene()

/** 
 * Objects
 */

const group = new THREE.Group();
scene.add(group);

group.position.y = 1;
group.scale.y = 1;

const cube1 = new THREE.Mesh(
    new THREE.BoxGeometry(1,1,1),
    new THREE.MeshBasicMaterial({ color: 0xff0000 }),
);
cube1.position.x = 0;

const cube2 = new THREE.Mesh(
    new THREE.BoxGeometry(1,1,1),
    new THREE.MeshBasicMaterial({ color: 0x00ff00 }),
);
cube2.position.x = -2;

const cube3 = new THREE.Mesh(
    new THREE.BoxGeometry(1,1,1),
    new THREE.MeshBasicMaterial({ color: 0x0000ff }),
);
cube3.position.x = 2;

group.add(cube1);
group.add(cube2);
group.add(cube3);

// Move object
//mesh.position.set(0.7, -0.6, 1.0)

// Scale object
//mesh.scale.set(2, 0.5, 0.5);

// Rotation (terms of pi)
//mesh.rotation.reorder('YXZ');
//mesh.rotation.set(0.25*Math.PI, 0.25*Math.PI, 0);

// Add axes
const axesHelper = new THREE.AxesHelper();
scene.add(axesHelper);


//scene.add(mesh)


/**
 * Sizes
 */
const sizes = {
    width: 800,
    height: 600
}

/**
 * Camera
 */
const camera = new THREE.PerspectiveCamera(75, sizes.width / sizes.height)
// camera.position.x = 1;
// camera.position.y = 1;
camera.position.z = 3;

// camera.lookAt(group);

scene.add(camera)


//camera.lookAt(mesh.position);


/**
 * Renderer
 */
const renderer = new THREE.WebGLRenderer({
    canvas: canvas
})
renderer.setSize(sizes.width, sizes.height)
renderer.render(scene, camera)