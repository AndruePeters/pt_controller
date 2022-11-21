/**
 * 
 * @param {string} tag 
 * @param {string} id 
 * @param {Array<string>} classList 
 * @param {Map<string,string>} props 
 */
export function createElement(tag, classList=null, id=null, props=null) {
    let element = document.createElement(tag);

    if (id != null) {
        element.id = id;
    }

    if (classList != null) {
        // element.classList.add(classList);
        for(const item of classList) {
            element.classList.add(item);
        }
    }

    if (props != null) {
        for (const [key, value] of props) {
            element.setAttribute(key, value);
        }
    }

    return element;
}