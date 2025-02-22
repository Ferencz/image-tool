import { createRequire } from 'module';
const require = createRequire(import.meta.url);
const cppAddon = require('./image-api/build/Release/image_api.node');
export default cppAddon;
